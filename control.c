/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 03:43:41 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/11 01:06:20 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void exep_file(t_env *e, t_file **file)
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

static void overload(t_env *e, char *str)
{
	if (e->overload == 1)
		ft_printf("\n%s:\n", str);
	else if (e->overload == 2)
		ft_printf("%s:\n", str);
	e->overload = 1;
}

void	controler(t_env *e, t_file **file, t_file **dir)
{
	t_file			*tmp;
	DIR				*directory;
	struct dirent	*dir_info;

	tmp = *dir;
	exep_file(e, file);
	if (tmp && list_len(dir) > 1)
	{
		sort_list(dir, e);
		if (e->overload == 0)
			e->overload = 2;
	}
	while (tmp)
	{
		overload(e, tmp->str);
		if ((directory = opendir(tmp->str)) == NULL)
		{
			error_dir(tmp->str, e);
			return ;
		}
		while ((dir_info = readdir(directory)) != NULL)
			add_link(dir_info->d_name, tmp->str, file);
		env_list(file, e);
		sort_list(file, e);
		print_list(file, e);
		if (e->f_rec == 1 && recur_list(file, dir, e) == 1)
			tmp = *dir;
		else
			tmp = tmp->next;
		del_list(file);
	}
	del_list(dir);
}
