/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:32:48 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/29 05:26:23 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
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


typedef struct s_file
{
	char			*str;
	struct s_file	*next;
}				t_file;

/*
** Parsing
*/
void	parse_arg(int argc, char **argv, t_env *e);

/*
** Print
*/
void path_to_list(char *dirpath, t_env *e, t_file **path);
void selector(t_env *e);
void ft_print_line(struct dirent *info, t_env *e, struct stat *info_file);
void print_mode(struct stat *info_file);
void print_link(struct stat *info_file);
void print_user(struct stat *info_file);
void print_group(struct stat *info_file);
void print_size(struct stat *info_file);
void print_time(struct stat *info_file);
/*
** Utils
*/
void error_dir(char *dirpath, t_env *e);
void add_link(char *path, t_file **file);
void print_list(t_file **list);

/*
** Sort
*/
void sort_list(t_file **list);
#endif
