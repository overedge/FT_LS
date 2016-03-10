/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:52:57 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/09 18:39:09 by nahmed-m         ###   ########.fr       */
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

int		good_file(char *str)
{
	if (ft_strlen(str) == 1 && str[0] == '.')
		return (1);
	if (ft_strlen(str) == 2 && str[0] == '.' && str[1] == '.')
		return (1);
	if (ft_strlen(str) > 1 && str[0] == '.' && str[1] != '.')
		return (1);
	return (0);
}
