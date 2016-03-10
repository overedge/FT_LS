/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 05:22:55 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/10 18:57:17 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			swap(t_file **swap, t_file **swap2)
{
	t_file		*swp;
	t_file		*swp2;
	char		*tmp;
	time_t		tmptime;
	long		nano;

	swp = *swap;
	swp2 = *swap2;
	tmp = swp->str;
	swp->str = swp2->str;
	swp2->str = tmp;
	tmptime = swp->timer;
	swp->timer = swp2->timer;
	swp2->timer = tmptime;
	tmp = swp->path;
	swp->path = swp2->path;
	swp2->path = tmp;
	tmp = swp->total;
	swp->total = swp2->total;
	swp2->total = tmp;
	nano = swp->nano;
	swp->nano = swp2->nano;
	swp2->nano = nano;
}

static void			sort_str(t_file **list, t_env *e)
{
	t_file *tmp;
	t_file *tmp2;

	tmp = *list;
	tmp2 = tmp->next;
	while (tmp2)
	{
		if (e->f_r == 0 ? ft_strcmp(tmp->str, tmp2->str) > 0 :
				ft_strcmp(tmp->str, tmp2->str) < 0)
		{
			swap(&tmp, &tmp2);
			tmp = *list;
			tmp2 = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
	}
}

static void			sort_nano(t_file **tmp, t_file **tmp2, t_env *e)
{
	t_file *val;
	t_file *val2;

	val = *tmp;
	val2 = *tmp2;
	if (e->f_r == 0 ? val->nano < val2->nano : val->nano > val2->nano)
		swap(&val, &val2);
}

static void			sort_time(t_file **list, t_env *e)
{
	t_file *tmp;
	t_file *tmp2;

	tmp = *list;
	tmp2 = tmp->next;
	while (tmp2)
	{
		if (e->f_r == 0 ? tmp->timer < tmp2->timer : tmp->timer > tmp2->timer)
		{
			swap(&tmp, &tmp2);
			tmp = *list;
			tmp2 = tmp->next;
		}
		if (tmp->timer == tmp2->timer)
		{
			sort_nano(&tmp, &tmp2, e);
			tmp = *list;
			tmp2 = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
	}
}

void				sort_list(t_file **list, t_env *e)
{
	if (e->f_t == 1)
	{
		sort_str(list, e);
		sort_time(list, e);
	}
	else
		sort_str(list, e);
}
