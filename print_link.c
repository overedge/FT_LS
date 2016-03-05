#include "ft_ls.h"

void print_link(struct stat info_file, t_env *e)
{
	ft_printf("%*d ", e->display->lnk + 2, info_file.st_nlink);
}
