/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 03:43:41 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/13 14:21:21 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		exep_file(t_env *e, t_file **file)
{
	t_file *tmp;

	tmp = *file;
	if (tmp)
	{
		env_list(file, e);
		sort_list(file, e);
		print_list(file, e);
		e->overload = 1;
		del_list(file);
	}
}

static void		overload(t_env *e, char *str)
{
	if (e->overload == 1)
		ft_printf("\n%s:\n", str);
	else if (e->overload == 2)
		ft_printf("%s:\n", str);
	e->overload = 1;
}

static void		del_current(t_file **dir, t_file **tmp, char *str, t_env *e)
{
	t_file			*tmp2;

	if (ft_strlen(str) != 0)
		error_dir(str, e);
	tmp2 = *tmp;
	*tmp = (*tmp)->next;
	free(tmp2);
	*dir = *tmp;
}

static void		dir_loop(t_env *e, t_file **file, t_file **dir)
{
	DIR				*directory;
	struct dirent	*dir_info;
	t_file			*tmp;

	tmp = *dir;
	while (tmp)
	{
		overload(e, tmp->str);
		if ((directory = opendir(tmp->str)) != NULL)
		{
			while ((dir_info = readdir(directory)) != NULL)
				add_link(dir_info->d_name, tmp->str, file);
			closedir(directory);
			env_list(file, e);
			sort_list(file, e);
			print_list(file, e);
			if (e->f_rec == 1 && recur_list(file, dir, e) == 1)
				tmp = *dir;
			else
				del_current(dir, &tmp, "", 0);
			del_list(file);
		}
		else
			del_current(dir, &tmp, tmp->str, e);
	}
}

void			controler(t_env *e, t_file **file, t_file **dir)
{
	t_file			*tmp;

	tmp = *dir;
	exep_file(e, file);
	if (tmp && list_len(dir) > 1)
	{
		sort_list(dir, e);
		if (e->overload == 0)
			e->overload = 2;
	}
	dir_loop(e, file, dir);
	del_list(dir);
}
