/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:42:29 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/12 19:18:31 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int ft_exep(char c, t_env *e)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
	e->exep = TRUE;
	e->error = TRUE;
	return (1);
}

static int		on_off(char *str, t_env *e)
{
	int		i;

	i = 1;
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
		else if (str[i] == '1')
			;
		else
			return (ft_exep(str[i], e));
		i++;
	}
	return (0);
}

static size_t		count_t(char *str)
{
	int		i;
	size_t	score_t;

	i = 0;
	score_t = 0;

	while (str[i])
	{
		if (str[i] == '-')
			score_t++;
		i++;
	}
	return (score_t);
}

void			parse_arg(int argc, char **argv, t_env *e)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 2 && argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (argc - i > 1)
				e->i = i + 1;
			else if (argc - i == 1)
				e->i = 0;
			else
				e->exep = 1;
			return ;
		}
		else if (argv[i][0] == '-' && ft_strlen(argv[i]) != 1 && count_t(argv[i]) < ft_strlen(argv[i]))
		{
			if (on_off(argv[i], e) == 1)
				return ;
		}
		else
		{
			e->i = i;
			return ;
		}
		i++;
	}
}
