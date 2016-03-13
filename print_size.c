/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 22:10:30 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/13 01:09:51 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_size(struct stat info_file, t_env *e)
{
	if (S_ISCHR(info_file.st_mode & S_IFMT))
		ft_printf("%3d, %3d ", major(info_file.st_rdev), \
				minor(info_file.st_rdev));
	else if (S_ISBLK(info_file.st_mode & S_IFMT))
		ft_printf("%3d, %3d ", major(info_file.st_rdev), \
				minor(info_file.st_rdev));
	else if (e->display->dev == 1 && e->f_a == 1)
		ft_printf("%*lld ", e->display->siz + 4, info_file.st_size);
	else if (e->display->dev == 1)
		ft_printf("%8lld ", info_file.st_size);
	else
		ft_printf("%*lld ", e->display->siz, info_file.st_size);
}
