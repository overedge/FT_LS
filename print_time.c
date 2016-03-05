/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 22:19:40 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/05 20:12:43 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_time(struct stat info_file, t_env *e)
{
	char *str;
	char **date;
	char **hour;

	str = ctime(&info_file.st_mtime);
	date = ft_strsplit(str, ' ');
	ft_printf("%-s ", date[1]);
	ft_printf("%2s ", date[2]);
	hour = ft_strsplit(date[3], ':');
	ft_printf("%-s:", hour[0]);
	ft_printf("%-s ", hour[1]);
	}
