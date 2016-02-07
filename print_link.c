#include "ft_ls.h"

void print_link(struct stat *info_file)
{
	ft_printf("%6d ", info_file->st_nlink);
}
