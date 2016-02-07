/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 23:37:17 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/06 23:43:10 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void special(struct stat *info_file)
{
	int mask;

	mask = info_file->st_mode & S_IFMT;
	if (mask == S_IFLNK)
		ft_putchar('l');
	else if (mask == S_IFDIR)
		ft_putchar('d');
	else if (mask == S_IFBLK)
		ft_putchar('b');
	else if (mask == S_IFCHR)
		ft_putchar('c');
	else if (mask == S_IFSOCK)
		ft_putchar('s');
	else if (mask == S_IFIFO)
		ft_putchar('p');
	else
		ft_putchar('-');
}

void	print_mode(struct stat *info_file)
{
	special(info_file);
	(info_file->st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(info_file->st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	(info_file->st_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(info_file->st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(info_file->st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	(info_file->st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(info_file->st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(info_file->st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	(info_file->st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
}
