/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:31:49 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/13 01:01:52 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		constructor(t_env *e, int argc, char **argv)
{
	e->f_rec = FALSE;
	e->f_l = FALSE;
	e->f_t = FALSE;
	e->f_r = FALSE;
	e->f_a = FALSE;
	e->f_e = FALSE;
	e->f_c = FALSE;
	e->exep = FALSE;
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
		while (save + 1 < e->argc)
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
	if (e.exep == 1)
		return (e.error);
	sort_argv(&e);
	file_or_dir(&e, &file, &dir);
	controler(&e, &file, &dir);
	return (e.error);
}
