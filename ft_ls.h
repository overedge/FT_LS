/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:32:48 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/13 13:43:55 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_display
{
	unsigned long	nb_block;
	int				lnk;
	long long		siz;
	unsigned long	grs;
	unsigned long	own;
	char			dev;
}				t_display;

typedef struct	s_env
{
	char		f_rec;
	char		f_l;
	char		f_t;
	char		f_r;
	char		f_a;
	char		f_e;
	char		f_c;
	char		exep;
	int			argc;
	char		**argv;
	int			i;
	char		error;
	char		overload;
	t_display	*display;
}				t_env;

typedef struct	s_file
{
	char			*str;
	char			*path;
	char			*total;
	time_t			timer;
	long int		nano;
	struct s_file	*next;
}				t_file;

/*
** Parsing
*/
void			parse_arg(int argc, char **argv, t_env *e);

/*
** Print
*/
void			print_mode(struct stat info_file);
void			print_link(struct stat info_file, t_env *e);
void			print_user(struct stat info_file, t_env *e);
void			print_group(struct stat info_file, t_env *e);
void			print_size(struct stat info_file, t_env *e);
void			print_time(struct stat info_file);
void			print_path(t_file *file, struct stat info_file, t_env *e);

/*
** Utils
*/
void			error_dir(char *dirpath, t_env *e);
void			add_link(char *name, char *path, t_file **file);
void			print_list(t_file **list, t_env *e);
void			del_list(t_file **list);
unsigned long	len_nbr(unsigned long nbr);
int				list_len(t_file **list);
int				good_file(char *str, t_env *e);
void			proces_list(struct stat list, t_env *e);
void			to_next(t_file **list, t_file **list1);
/*
** Sort
*/
void			sort_list(t_file **list, t_env *e);

/*
** File Or Dir
*/
void			file_or_dir(t_env *e, t_file **file, t_file **dir);
void			detect_dir(t_env *e, char *path, t_file **file, t_file **dir);

/*
** Controler
*/
void			controler(t_env *e, t_file **file, t_file **dir);

/*
** Env List
*/
void			env_list(t_file **list, t_env *e);

/*
** Recur List
*/
int				recur_list(t_file **list, t_file **dir, t_env *e);
#endif
