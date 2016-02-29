/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 20:20:14 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/29 05:20:56 by nahmed-m         ###   ########.fr       */
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

void	print_list(t_file **list)
{
	t_file *tmp;

	tmp = *list;
	while(tmp)
	{
		ft_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}
