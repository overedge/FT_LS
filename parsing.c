/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:42:29 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/11 17:37:51 by nahmed-m         ###   ########.fr       */
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
			e->f_rec = TRUE;
		else if (str[i] == 'r')
			e->f_r = TRUE;
		else if (str[i] == 'l')
			e->f_l = TRUE;
		else if (str[i] == 't')
			e->f_t = TRUE;
		else if (str[i] == 'a')
			e->f_a = TRUE;
		else if (str[i] == 'e')
			e->f_e = TRUE;
		else if (str[i] == 'c')
			e->f_c = TRUE;
		i++;
	}
}

static int		count_t(char *str)
{
	int		score;
	int		i;

	score = ft_strlen(str);
	i = 0;

	while (str[i])
	{
		
		i++;
	}

}

void			parse_arg(int argc, char **argv, t_env *e)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && ft_strlen(argv[i]) != 1 && count_t(argv[i]) != 1)
			on_off(argv[i], e);
		else
		{
			e->i = i;
			return ;
		}
		i++;
	}
}
