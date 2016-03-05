/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 20:20:14 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/04 20:23:36 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_dir(char *dirpath, t_env *e)
{
	perror(dirpath);
	e->error = 1;
}

void	add_link(char *path, t_file **file)
{
	t_file *tmp;
	t_file *new;

	tmp = *file;
	new = (t_file*)malloc(sizeof(t_file));
	new->str = ft_strdup(path);
	new->next = NULL;
	if (!tmp)
	{
		*file = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	print_list(t_file **list, t_env *e)
{
	t_file *tmp;
	struct stat info_file;
	char		*test;

	tmp = *list;
	if (tmp && e->f_l == 1 && e->overload == 1)
		ft_printf("total %ld\n", e->display->nb_block);
	while(tmp)
	{
		if (e->f_a == 0 && tmp->str[0] == '.')
			tmp = tmp->next;
		else
		{
			if (e->f_l == 1)
			{
				lstat(tmp->str, &info_file);
				print_mode(info_file);
				print_link(info_file);
				print_user(info_file);
				print_group(info_file);
				print_size(info_file);
				print_time(info_file);
			}
		ft_printf("%s\n", tmp->str);
		tmp = tmp->next;
		}
	}
}

void	del_list(t_file **list)
{
	t_file *tmp;

	tmp = *list;

	while (tmp)
	{
		*list = tmp->next;
		free(tmp);
		tmp = *list;
	}
	tmp = NULL;
	list = NULL;
}

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
	while (tmp)
	{
		lstat(tmp->str, &info);
		if (e->f_a == 0 && tmp->str[0] == '.')
			display->nb_block = display->nb_block;
		else
			display->nb_block += info.st_blocks;
		tmp = tmp->next;
	}
	e->display = display;
}
