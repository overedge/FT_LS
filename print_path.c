/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:38:15 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/05 15:49:45 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void path_link(char *str, struct stat infos_file, t_env *e)
{
	char *linkname;
	
	linkname = (char *)malloc(sizeof(infos_file.st_size + 1));
	
	if (readlink(str, linkname, infos_file.st_size + 1) == -1)
		error_dir(str, e);
	else
	{
		if (e->f_c == 1)
			ft_printf("\033[1;35m%s\033[m -> %s", str, linkname);
		else
			ft_printf("%s -> %s", str, linkname);
		if (e->f_e == 1)
			ft_printf(" 🚩");
	}
	free(linkname);
}

void print_path(char *str, struct stat infos_file, t_env *e)
{
	if (e->f_l == 1 && S_ISLNK(infos_file.st_mode & S_IFMT))
		path_link(str, infos_file, e);
	else
	{
		if (e->f_c == 1 && S_ISDIR(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;34m%s\033[m", str);
		else if (e->f_c == 1 && S_ISREG(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;32m%s\033[m", str);
		else if (e->f_c == 1 && S_ISLNK(infos_file.st_mode & S_IFMT))
			ft_printf("\033[1;35m%s\033[m", str);
		else
			ft_printf("%s", str);
		if (e->f_e == 1 && S_ISDIR(infos_file.st_mode & S_IFMT))
			ft_printf(" 📁");
		else if (e->f_e == 1 && S_ISLNK(infos_file.st_mode & S_IFMT))
			ft_printf(" 🚩");
		else if (e->f_e == 1 && S_ISREG(infos_file.st_mode & S_IFMT))
			ft_printf(" 📄");
	}
	ft_putchar('\n');
}
