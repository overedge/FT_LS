/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 23:37:17 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/08 00:33:48 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			special(struct stat info_file)
{
	if (S_ISLNK(info_file.st_mode & S_IFMT))
		ft_putchar('l');
	else if (S_ISDIR(info_file.st_mode & S_IFMT))
		ft_putchar('d');
	else if (S_ISBLK(info_file.st_mode & S_IFMT))
		ft_putchar('b');
	else if (S_ISCHR(info_file.st_mode & S_IFMT))
		ft_putchar('c');
	else if (S_ISSOCK(info_file.st_mode & S_IFMT))
		ft_putchar('s');
	else if (S_ISFIFO(info_file.st_mode & S_IFMT))
		ft_putchar('p');
	else
		ft_putchar('-');
}

static void			print_mode_usr(struct stat info_file)
{
	if (S_IXUSR & info_file.st_mode && S_ISUID & info_file.st_mode)
		ft_putchar('s');
	else if (S_IXUSR & info_file.st_mode)
		ft_putchar('x');
	else if (S_ISUID & info_file.st_mode)
		ft_putchar('S');
	else
		ft_putchar('-');
}

static void			print_mode_grp(struct stat info_file)
{
	if (S_IXGRP & info_file.st_mode && S_ISGID & info_file.st_mode)
		ft_putchar('s');
	else if (S_IXGRP & info_file.st_mode)
		ft_putchar('x');
	else if (S_ISGID & info_file.st_mode)
		ft_putchar('S');
	else
		ft_putchar('-');
}

static void			print_mode_oth(struct stat info_file)
{
	if (S_IXOTH & info_file.st_mode && S_ISVTX & info_file.st_mode)
		ft_putchar('t');
	else if (S_IXOTH & info_file.st_mode)
		ft_putchar('x');
	else if (S_ISVTX & info_file.st_mode)
		ft_putchar('T');
	else
		ft_putchar('-');
}

void				print_mode(struct stat info_file)
{
	special(info_file);
	(info_file.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(info_file.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	print_mode_usr(info_file);
	(info_file.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(info_file.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	print_mode_grp(info_file);
	(info_file.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(info_file.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	print_mode_oth(info_file);
}
