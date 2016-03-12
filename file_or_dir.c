/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_or_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 00:38:51 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/12 22:59:39 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	detect_dir(t_env *e, char *path, t_file **file, t_file **dir)
{
	struct stat file_info;
	DIR			*directory;

	if (lstat(path, &file_info) == 0)
	{
		if (ft_strcmp(path, "/etc") == 0 || ft_strcmp(path, "/var") == 0)
			add_link(path, "", file);
		else if ((file_info.st_mode & S_IFMT) == S_IFDIR)
			add_link(path, "", dir);
		else if ((file_info.st_mode & S_IFMT) == S_IFLNK)
		{
			if ((directory = opendir(path)) != NULL)
			{
				add_link(path, "", dir);
				closedir(directory);
			}
			else
				add_link(path, "", file);
		}
		else
			add_link(path, "", file);
	}
	else
	{
		error_dir(path, e);
		e->overload = 2;
	}
}

void	file_or_dir(t_env *e, t_file **file, t_file **dir)
{
	if (e->i == 0)
		detect_dir(e, ".", file, dir);
	else
	{
		while (e->i < e->argc && e->i != 0)
		{
			detect_dir(e, e->argv[e->i], file, dir);
			e->i++;
		}
	}
}
