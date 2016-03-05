/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:58:16 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/05 20:17:42 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void env_list(t_file **list, t_env *e)
{
	t_file *tmp;
	struct stat info;
	t_display *display;

	tmp = *list;
	if (e->display)
		free(display);
	display = malloc(sizeof(t_display));
	display->nb_block = 0;
	display->lnk = 0;
	display->siz = 0;
	while (tmp)
	{
		lstat(tmp->str, &info);
		if (e->f_a == 0 && tmp->str[0] == '.')
			;
		else
		{
			display->nb_block += info.st_blocks;
			info.st_nlink > display->lnk ? display->lnk = info.st_nlink : 0;
			info.st_size > display->siz ? display->siz = info.st_size : 0;
		}
		tmp = tmp->next;
	}
	e->display = display;
	e->display->lnk = len_nbr(e->display->lnk);
	e->display->siz = len_nbr(e->display->siz);
}
