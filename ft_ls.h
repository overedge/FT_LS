/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:32:48 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/08 13:45:24 by nahmed-m         ###   ########.fr       */
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
	char *str;
}				t_file;
/*
** Parsing
*/
void	parse_arg(int argc, char **argv, t_env *e);

/*
** Print
*/
void print_upper_a(char *dirpath, t_env *e);
void print_lower(char *dirpath, t_env *e);
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
int		ft_isupper(char c);
int		ft_islower(char c);
#endif
