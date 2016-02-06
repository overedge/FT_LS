/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:42:29 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/06 01:18:33 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		on_off(char *str, t_env *e)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'R')
			e->f_R = TRUE;
		else if (str[i] == 'r')
			e->f_r = TRUE;
		else if (str[i] == 'l')
			e->f_l = TRUE;
		else if (str[i] == 't')
			e->f_t = TRUE;
		else if (str[i] == 'a')
			e->f_a = TRUE;
		i++;
	}
}

void			parse_arg(int argc, char **argv, t_env *e)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			on_off(argv[i], e);
		else
		{
			e->i = i;
			ft_printf("il y a %d args", e->i);
			return ;
		}
		i++;
	}
}
