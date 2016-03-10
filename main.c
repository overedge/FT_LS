/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:31:49 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/10 15:35:36 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//static void		debug(t_env *e)
//{
//	if (e->f_rec == TRUE)
//		ft_printf("Flags '-R' Actived\n");
//	if (e->f_r == TRUE)
//		ft_printf("Flags '-r' Actived\n");
//	if (e->f_l == TRUE)
//		ft_printf("Flags '-l' Actived\n");
//	if (e->f_t == TRUE)
//		ft_printf("Flags '-t' Actived\n");
//	if (e->f_a == TRUE)
//		ft_printf("Flags '-a' Actived\n");
//	if (e->f_e == TRUE)
//		ft_printf("Flags '-e' Actived\n");
//	if (e->f_c == TRUE)
//		ft_printf("Flags '-c' Actived\n");
//	while (e->i < e->argc && e->i != 0)
//	{
//		ft_printf("ARGS : %s\n", e->argv[e->i]);
//		e->i++;
//	}
//}

static void		constructor(t_env *e, int argc, char **argv)
{
	e->f_rec = FALSE;
	e->f_l = FALSE;
	e->f_t = FALSE;
	e->f_r = FALSE;
	e->f_a = FALSE;
	e->f_e = FALSE;
	e->f_c = FALSE;
	e->error = FALSE;
	e->overload = FALSE;
	e->i = FALSE;
	e->argc = argc;
	e->argv = argv;
}

static void		sort_argv(t_env *e)
{
	int		save;
	char	*swap;

	save = e->i;
	if (e->i == 0)
		return ;
	else
	{
		while(save + 1 < e->argc)
		{
			if (ft_strcmp(e->argv[save], e->argv[save + 1]) > 0)
			{
				swap = e->argv[save];
				e->argv[save] = e->argv[save + 1];
				e->argv[save + 1] = swap;
				save = e->i;
			}
			else
				save += 1;
		}
	}
}

int				main(int argc, char **argv)
{
	t_env	e;
	t_file	*file;
	t_file	*dir;

	file = NULL;
	dir = NULL;
	constructor(&e, argc, argv);
	if (argc > 1)
		parse_arg(argc, argv, &e);
//	debug(&e);
	sort_argv(&e);
	file_or_dir(&e, &file, &dir);
	controler(&e, &file, &dir);
	return (e.error);
}
