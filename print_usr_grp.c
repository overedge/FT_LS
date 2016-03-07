#include "ft_ls.h"

void print_group(struct stat info_file, t_env *e)
{
	struct group *group;

	if ((group = getgrgid(info_file.st_gid)) == NULL)
	{
		perror("");
		return ;
	}
	ft_printf("%-*s  ", e->display->grs, group->gr_name);
}

void print_user(struct stat info_file, t_env *e)
{
	struct passwd *user;

	if ((user = getpwuid(info_file.st_uid)) == NULL)
	{
		perror("");
		return;
	}
	ft_printf("%-*s  ", e->display->own , user->pw_name);
}
