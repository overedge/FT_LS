/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:52:57 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/06 22:02:30 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int list_len(t_file **list)
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

int count_slash(char *str)
{
	int		i;
	int		score;

	i = 0;
	score = 0;
	while (str[i])
	{
		if (str[i] == '/')
			score++;
		i++;
	}
	if (score == 1)
		return (0);
	return (score);
}
