/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 23:37:17 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/03 15:39:32 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void special(struct stat *info_file)
{
	if (S_ISLNK(info_file->st_mode & S_IFMT))
		ft_putchar('l');
	else if (S_ISDIR(info_file->st_mode & S_IFMT))
		ft_putchar('d');
	else if (S_ISBLK(info_file->st_mode & S_IFMT))
		ft_putchar('b');
	else if (S_ISCHR(info_file->st_mode & S_IFMT))
		ft_putchar('c');
	else if (S_ISSOCK(info_file->st_mode & S_IFMT))
		ft_putchar('s');
	else if (S_ISFIFO(info_file->st_mode & S_IFMT))
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
