/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 03:43:41 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/29 16:55:37 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_print_line(t_file **list)
{
	t_file *tmp;
	struct stat info_file;

	tmp = *list;
	while (tmp)
	{
		stat(tmp->str, &info_file);
		print_mode(&info_file);
		print_link(&info_file);
		print_user(&info_file);
		print_group(&info_file);
		print_size(&info_file);
		print_time(&info_file);
		ft_printf(" %s\n", tmp->str);
		tmp = tmp->next;
	}
}

void path_to_list(char *dirpath, t_env *e, t_file **path)
{
	DIR				*directory;
	struct dirent	*infos;
	
	if ((directory = opendir(dirpath)) == NULL)
	{
		error_dir(dirpath, e);
		return ;
	}
	while ((infos = readdir(directory)) != NULL)
	{
		if (e->f_a == 0 && infos->d_name[0] != '.')
			add_link(infos->d_name, path);
	}
	if (closedir(directory) == -1)
		perror("");
	}

static void next_selector(t_file **path, t_env *e)
{
	sort_list(path);
	if (e->f_l == 0)
		print_list(path);
	else
		ft_print_line(path);
	del_list(path);
}

void	selector(t_env *e)
{
	t_file *path = NULL;

	if (e->i == 0 || e->i == 1)
	{
		if (e->i == 0)
			path_to_list(".", e, &path);
		else
			path_to_list(e->argv[1], e, &path);
		next_selector(&path, e);
	}
	else
	{
		while (e->i < e->argc && e->i != 0)
		{
			ft_printf("%s:\n", e->argv[e->i]);
			path_to_list(e->argv[e->i], e, &path);
			next_selector(&path, e);
			ft_putchar('\n');
			e->i++;
		}
	}
}
