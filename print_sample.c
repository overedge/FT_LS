/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 20:18:11 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/05 21:06:39 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_simple(char *dirpath, t_env *e)
{
	DIR 			*directory;
	struct dirent	*infos;

	if ((directory = opendir(dirpath)) == NULL)
	{
		error_dir(dirpath, e);
		return ;
	}
	while ((infos = readdir(directory)) != NULL)
	{
		if (infos->d_name[0] != '.')
			ft_printf("%s\n", infos->d_name);
	}
	if (closedir(directory) == -1)
		perror("");
}
