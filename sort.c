/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 05:22:55 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/29 16:16:29 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void swap(char **str, char **str2)
{
	char *tmp;

	tmp = *str;
	*str = *str2;
	*str2 = tmp;
}

void sort_list(t_file **list)
{
	t_file *tmp;
	t_file *tmp2;

	tmp = *list;
	tmp2 = tmp->next;
	while (tmp2)
	{
		if (ft_strcmp(tmp->str, tmp2->str) > 0)
		{
			swap(&tmp->str, &tmp2->str);
			tmp = *list;
			tmp2 = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
	}
}
