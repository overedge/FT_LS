/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 03:43:41 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/04 19:55:32 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void exep_file(t_env *e, t_file **file)
{
	t_file *tmp;
	
	tmp = *file;
	if (tmp)
	{
		e->overload = 1;
		sort_list(file, e);
		print_list(file, e);
		del_list(file);
	}
}

void	controler(t_env *e, t_file **file, t_file **dir)
{
	t_file			*tmp;
	DIR				*directory;
	struct dirent	*dir_info;

	tmp = *dir;
	exep_file(e, file);
	if (tmp)
		sort_list(dir, e);
	while (tmp)
	{
		if (e->overload == 1)
			ft_printf("\n%s:\n", tmp->str);
		directory = opendir(tmp->str);
		while ((dir_info = readdir(directory)) != NULL)
			add_link(dir_info->d_name, file);
		env_list(file, e);
		sort_list(file, e);
		print_list(file, e);
		del_list(file);
		tmp = tmp->next;
	}
}
