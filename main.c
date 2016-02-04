/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:31:49 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/04 20:42:31 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void debug(t_env *e)
{
	if (e->f_R == TRUE)
		ft_printf("Flags '-R' Actived\n");
	if (e->f_r == TRUE)
		ft_printf("Flags '-r' Actived\n");
	if (e->f_l == TRUE)
		ft_printf("Flags '-l' Actived\n");
	if (e->f_t == TRUE)
		ft_printf("Flags '-t' Actived\n");
	if (e->f_a == TRUE)
		ft_printf("Flags '-a' Actived\n");
	while (e->i < e->argc)
	{
		ft_printf("ARGS : %s\n", e->argv[e->i]);
		e->i++;
	}
}

int		main(int argc, char **argv)
{
	t_env e;

	e.f_R = FALSE;
	e.f_l = FALSE;
	e.f_t = FALSE;
	e.f_r = FALSE;
	e.f_a = FALSE;
	e.argc = argc;
	e.argv = argv;
	parse_arg(argc, argv, &e);
	debug(&e);
	return (0);
}
