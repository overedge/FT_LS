/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:52:57 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/13 01:53:44 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		list_len(t_file **list)
{
	t_file	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		good_file(char *str, t_env *e)
{
	if (ft_strlen(str) == 1 && str[0] == '.')
		return (1);
	if (ft_strlen(str) == 2 && str[0] == '.' && str[1] == '.')
		return (1);
	if (ft_strlen(str) > 1 && str[0] == '.' && str[1] != '.' && e->f_a == 1
			&& e->f_rec == 1)
		return (0);
	if (ft_strlen(str) > 1 && str[0] == '.' && str[1] != '.')
		return (1);
	return (0);
}

void	proces_list(struct stat list, t_env *e)
{
	print_mode(list);
	print_link(list, e);
	print_user(list, e);
	print_group(list, e);
	print_size(list, e);
	print_time(list);
}
