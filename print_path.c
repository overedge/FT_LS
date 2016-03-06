/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:38:15 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/06 22:23:55 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void path_link(char *str, struct stat infos_file, t_env *e)
{
	char *linkname;
	
	linkname = (char *)malloc(sizeof(infos_file.st_size + 1));
	
	if (readlink(str, linkname, infos_file.st_size + 1) == -1)
		error_dir(path(str), e);
	else
	{
		if (e->f_c == 1)
			ft_printf("\033[1;35m%s\033[m -> %s", path(str), linkname);
		else
			ft_printf("%s -> %s", path(str), linkname);
		if (e->f_e == 1)
			ft_printf(" 🚩");
	}
	free(linkname);
}

void static print_emoji(struct stat infos_file)
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

void print_path(char *str, struct stat infos_file, t_env *e)
{
	if (e->f_l == 1 && S_ISLNK(infos_file.st_mode & S_IFMT))
		path_link(str, infos_file, e);
	else
	{
		if (e->f_c == 1 && S_ISDIR(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;34m%s\033[m", path(str));
		else if (e->f_c == 1 && S_ISREG(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;32m%s\033[m", path(str));
		else if (e->f_c == 1 && S_ISLNK(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;35m%s\033[m", path(str));
		else if (e->f_c == 1 && S_ISFIFO(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;31m%s\033[m", path(str));
		else if (e->f_c == 1 && S_ISBLK(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;33m%s\033[m", path(str));
		else if (e->f_c == 1 && S_ISCHR(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;36m%s\033[m", path(str));
		else if (e->f_c == 1 && S_ISSOCK(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;37m%s\033[m", path(str));
		else
			ft_printf("%s", path(str));
		if (e->f_e == 1)
			print_emoji(infos_file);
	}
	ft_putchar('\n');
}
