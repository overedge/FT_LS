/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:42:29 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/13 02:06:39 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int				ft_exep(char c, t_env *e)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(
	"usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 2);
	e->exep = TRUE;
	e->error = TRUE;
	return (1);
}

static int				on_off(char *str, t_env *e)
{
	str++;
	while (*str != '\0')
	{
		if (*str == 'R')
			e->f_rec = TRUE;
		else if (*str == 'r')
			e->f_r = TRUE;
		else if (*str == 'l')
			e->f_l = TRUE;
		else if (*str == 't')
			e->f_t = TRUE;
		else if (*str == 'a')
			e->f_a = TRUE;
		else if (*str == 'e')
			e->f_e = TRUE;
		else if (*str == 'c')
			e->f_c = TRUE;
		else if (*str == '1')
			;
		else
			return (ft_exep(*str, e));
		str++;
	}
	return (0);
}

static size_t			count_t(char *str)
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

static void				handlin_check(int i, t_env *e, int argc)
{
	if (argc - i > 1)
		e->i = i + 1;
	else if (argc - i == 1)
		e->i = 0;
	else
		e->exep = 1;
}

void					parse_arg(int argc, char **argv, t_env *e)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 2 && argv[i][0] == '-' && argv[i][1] == '-')
		{
			handlin_check(i, e, argc);
			return ;
		}
		else if (argv[i][0] == '-' && ft_strlen(argv[i]) != 1 &&
				count_t(argv[i]) < ft_strlen(argv[i]))
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
