#include "ft_ls.h"

static int len_nbr(int nbr)
{
	int		i;

	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
void print_link(struct stat info_file, t_env *e)
{
	e->display->lnk = len_nbr(e->display->lnk);
	ft_putspace(e->display->lnk);
	ft_printf("%d ", info_file.st_nlink);
}
