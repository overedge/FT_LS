/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:58:16 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/07 22:42:18 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void construct_display(t_display *display)
{
	display->nb_block = 0;
	display->lnk = 0;
	display->siz = 0;
	display->grs = 0;
	display->own = 0;
	display->dev = 0;
}

static int size_env(struct stat info, t_env *e)
{
	struct group *group;
	struct passwd *user;

	if ((group = getgrgid(info.st_gid)) == NULL)
	{
		perror("");
		return (1);
	}
	if ((user = getpwuid(info.st_uid)) == NULL)
	{
		perror("");
		return (1);
	}
	e->display->nb_block += info.st_blocks;
	info.st_nlink > e->display->lnk ? e->display->lnk = info.st_nlink : 0;
	info.st_size > e->display->siz ? e->display->siz = info.st_size : 0;
	ft_strlen(group->gr_name) > e->display->grs ? e->display->grs = ft_strlen(group->gr_name) : 0;
	ft_strlen(user->pw_name) > e->display->own ? e->display->own = ft_strlen(user->pw_name) : 0;
	S_ISCHR(info.st_mode & S_IFMT) ? e->display->dev = 1 : 0;
	S_ISBLK(info.st_mode & S_IFMT) ? e->display->dev = 1 : 0;
	return (0);
}

void env_list(t_file **list, t_env *e)
{
	t_file *tmp;
	struct stat info;
	t_display *display;

	tmp = *list;
	display = malloc(sizeof(t_display));
	construct_display(display);
	e->display = display;
	while (tmp)
	{
		if (lstat(tmp->total, &info) != 0)
			error_dir(tmp->str, e);
		tmp->timer = info.st_mtime;
		if (e->f_a == 0 && tmp->str[0] == '.')
			;
		else
		{
			if (size_env(info, e) != 0)
				return ;
		}
		tmp = tmp->next;
	}
	e->display->lnk = len_nbr(e->display->lnk);
	e->display->siz = len_nbr(e->display->siz);
}
