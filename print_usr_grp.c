#include "ft_ls.h"

void print_group(struct stat info_file)
{
	struct group *group;

	if ((group = getgrgid(info_file.st_gid)) == NULL)
	{
		perror("");
		return ;
	}
	ft_printf("%s  ", group->gr_name);
}

void print_user(struct stat info_file)
{
	struct passwd *user;

	if ((user = getpwuid(info_file.st_uid)) == NULL)
	{
		perror("");
		return;
	}
	ft_printf("%s  ", user->pw_name);
}
