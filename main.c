/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:31:49 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/04 00:47:26 by nahmed-m         ###   ########.fr       */
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
	while (e->i < e->argc && e->i != 0)
	{
		ft_printf("ARGS : %s\n", e->argv[e->i]);
		e->i++;
	}
}

static void constructor(t_env *e, int argc, char **argv)
{
	e->f_R = FALSE;
	e->f_l = FALSE;
	e->f_t = FALSE;
	e->f_r = FALSE;
	e->f_a = FALSE;
	e->error = 0;
	e->overload = 0;
	e->i = 0;
}

int		main(int argc, char **argv)
{
	t_env e;
	t_file *file = NULL;
	t_file *dir = NULL;
	
	e.argc = argc;
	e.argv = argv;
	constructor(&e, argc, argv);
	if (argc > 1)
		parse_arg(argc, argv, &e);
//	debug(&e);
	file_or_dir(&e, &file, &dir);
	controler(&e, &file, &dir);
	return (e.error);
}
