/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:53:16 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/11 00:40:08 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void merge_list(t_file **dir, t_file **dirnew)
{
	t_file *tmp;
	t_file *tmp2;
	t_file *tmp3;

	tmp = *dirnew;
	tmp2 = *dir;
	tmp3 = *dir;
	tmp2 = tmp2->next;
	free(tmp3);
	*dir = tmp2;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *dir;
	*dir = *dirnew;
}

int		recur_list(t_file **file, t_file **dir, t_env *e)
{
	t_file		*tmp;
	t_file		*tmp2;
	struct stat info_file;
	t_file		*dirtmp = NULL;

	tmp = *file;
	tmp2 = *dir;
	while (tmp)
	{
		if (!good_file(tmp->str))
		{
			if (lstat(tmp->total, &info_file) == -1)
				error_dir(tmp->str, e);
			if (S_ISDIR(info_file.st_mode & S_IFMT))
				add_link(tmp->str, tmp->path, &dirtmp);
		}
		tmp = tmp->next;
	}
	if (dirtmp)
	{
		merge_list(dir, &dirtmp);
		return (1);
	}
	else
		tmp2 = tmp2->next;
	return (0);
}
