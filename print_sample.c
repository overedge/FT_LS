/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 20:18:11 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/08 02:49:04 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_print_line(struct dirent *infos, t_env *e, struct stat *info_file)
{
	print_mode(info_file);
	print_link(info_file);
	print_user(info_file);
	print_group(info_file);
	print_size(info_file);
	print_time(info_file);
}

void	print_upper_a(char *dirpath, t_env *e)
{
	DIR			*directory;
	struct stat		info_file;
	struct dirent	*infos;

	if ((directory = opendir(dirpath)) == NULL)
	{
		error_dir(dirpath, e);
		return ;
	}
	while ((infos = readdir(directory)) != NULL)
	{
		stat(infos->d_name, &info_file);
		if ((e->f_l == 1 && infos->d_name[0] != '.' && (ft_isupper(infos->d_name[0]) || ft_isdigit(infos->d_name[0]))) || (e->f_l == 1 && e->f_a == 1 && infos->d_name[0] == '.'))
			ft_print_line(infos, e, &info_file);
		if ((infos->d_name[0] != '.' && (ft_isupper(infos->d_name[0]) || ft_isdigit(infos->d_name[0]))) || (e->f_a == TRUE && infos->d_name[0] == '.'))
			ft_printf("%s\n", infos->d_name);
	}
	if (closedir(directory) == -1)
		perror("");
}

void	print_lower(char *dirpath, t_env *e)
{
	DIR			*directory;
	struct stat		info_file;
	struct dirent	*infos;

	if ((directory = opendir(dirpath)) == NULL)
	{
		error_dir(dirpath, e);
		return ;
	}
	while ((infos = readdir(directory)) != NULL)
	{
		stat(infos->d_name, &info_file);
		if (e->f_l == 1 && ft_islower(infos->d_name[0]))
			ft_print_line(infos, e, &info_file);
		if (ft_islower(infos->d_name[0]))
			ft_printf("%s\n", infos->d_name);
	}
	if (closedir(directory) == -1)
		perror("");
}

void	selector(t_env *e)
{
	if (e->i == 0)
	{
		print_upper_a(".", e);
		print_lower(".", e);
	}
	while (e->i < e->argc && e->i != 0)
	{
		print_upper_a(e->argv[e->i], e);
		print_lower(e->argv[e->i], e);
		e->i++;
	}
}
