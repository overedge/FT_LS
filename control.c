/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 03:43:41 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/29 05:27:03 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_print_line(struct dirent *infos, t_env *e, struct stat *info_file)
{
	print_mode(info_file);
	print_link(info_file);
	print_user(info_file);
	print_group(info_file);
	print_size(info_file);
	print_time(info_file);
}

void path_to_list(char *dirpath, t_env *e, t_file **path)
{
	DIR				*directory;
	struct dirent	*infos;
	
	if ((directory = opendir(dirpath)) == NULL)
	{
		error_dir(dirpath, e);
		return ;
	}
	while ((infos = readdir(directory)) != NULL)
		add_link(infos->d_name, path);
	if (closedir(directory) == -1)
		perror("");
	}

void	selector(t_env *e)
{
	t_file *path = NULL;

	if (e->i == 0)
	{
		path_to_list(".", e, &path);
		print_list(&path);
	}
	while (e->i < e->argc && e->i != 0)
	{
		path_to_list(e->argv[e->i], e, &path);
		print_list(&path);
		sort_list(&path);
		//print list
		//del list
		e->i++;
	}
}
