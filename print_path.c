/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:38:15 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/13 01:19:58 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		path_link(t_file *tmp, t_env *e)
{
	char *linkname;

	linkname = (char *)ft_memalloc(1025);
	if (readlink(tmp->total, linkname, 1024) == -1)
	{
		error_dir(tmp->str, e);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (e->f_c == 1)
			ft_printf("\033[1;35m%s\033[m -> %s", tmp->str, linkname);
		else
			ft_printf("%s -> %s", tmp->str, linkname);
		if (e->f_e == 1)
			ft_printf(" 🚩");
	}
	free(linkname);
}

static void		print_emoji(struct stat infos_file)
{
	if (S_ISDIR(infos_file.st_mode & S_IFMT))
		ft_printf(" 📁");
	else if (S_ISLNK(infos_file.st_mode & S_IFMT))
		ft_printf(" 🚩");
	else if (S_ISREG(infos_file.st_mode & S_IFMT))
		ft_printf(" 📄");
	else if (S_ISFIFO(infos_file.st_mode & S_IFMT))
		ft_printf(" 📡");
	else if (S_ISBLK(infos_file.st_mode & S_IFMT))
		ft_printf(" 🆔");
	else if (S_ISCHR(infos_file.st_mode & S_IFMT))
		ft_printf(" 💻");
	else if (S_ISSOCK(infos_file.st_mode & S_IFMT))
		ft_printf(" 📶");
}

void			print_path(t_file *tmp, struct stat infos_file, t_env *e)
{
	if (e->f_l == 1 && S_ISLNK(infos_file.st_mode & S_IFMT))
		path_link(tmp, e);
	else
	{
		if (e->f_c == 1 && S_ISDIR(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;34m%s\033[m", tmp->str);
		else if (e->f_c == 1 && S_ISREG(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;32m%s\033[m", tmp->str);
		else if (e->f_c == 1 && S_ISLNK(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;35m%s\033[m", tmp->str);
		else if (e->f_c == 1 && S_ISFIFO(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;31m%s\033[m", tmp->str);
		else if (e->f_c == 1 && S_ISBLK(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;33m%s\033[m", tmp->str);
		else if (e->f_c == 1 && S_ISCHR(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;36m%s\033[m", tmp->str);
		else if (e->f_c == 1 && S_ISSOCK(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;37m%s\033[m", tmp->str);
		else
			ft_printf("%s", tmp->str);
		if (e->f_e == 1)
			print_emoji(infos_file);
	}
	ft_putchar('\n');
}
