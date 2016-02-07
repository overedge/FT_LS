/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:32:48 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/06 23:58:08 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# define TRUE 1
# define FALSE 0

typedef struct s_env
{
	char	f_R;
	char	f_l;
	char	f_t;
	char	f_r;
	char	f_a;
	int		argc;
	char	**argv;
	int		i;
	char	error;
}				t_env;

/*
** Parsing
*/
void	parse_arg(int argc, char **argv, t_env *e);

/*
** Print
*/
void print_simple(char *dirpath, t_env *e);
void selector(t_env *e);
void ft_print_line(struct dirent *info, t_env *e, struct stat *info_file);
void print_mode(struct dirent *info, t_env *e, struct stat *info_file);
/*
** Utils
*/
void error_dir(char *dirpath, t_env *e);

#endif
