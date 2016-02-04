/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:31:49 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/02/04 17:30:09 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <grp.h>
#include <locale.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void recur_chiotte(char *filename)
{
	DIR *test;
	struct dirent *result;
	struct stat statbuf;
	test = opendir(filename);
	if (!test)
		perror("");
	else
	{
	while ((result = readdir(test)) != NULL)
		{
			if (!result)
				perror("");
			else
			{
				if (stat(result->d_name, &statbuf) == -1)
					perror(result->d_name);
				ft_printf("Nom du fichier : %s\n", result->d_name);
				if (result->d_type == DT_BLK)
					ft_printf("Type :  périphérique de blocs.\n");
				else if (result->d_type == DT_CHR)
					ft_printf("Type :  périphérique de caractères.\n");
				else if (result->d_type == DT_DIR)
					ft_printf("Type :  Repertoire\n");
				else if (result->d_type == DT_FIFO)
					ft_printf("Type :  TUBE\n");
				else if (result->d_type == DT_LNK)
					ft_printf("Type :  LINK\n");
				else if (result->d_type == DT_REG)
					ft_printf("Type :  Fichier\n");
				else if (result->d_type == DT_SOCK)
					ft_printf("Type :  SOCKET\n");
				else if (result->d_type == DT_UNKNOWN)
					ft_printf("Type :  Inconnue\n");
				int statchmod = statbuf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
				ft_printf("chmod: %o\n", statchmod);
				ft_printf("link : %4d\n", statbuf.st_nlink);
				ft_printf("size : %lu\n", statbuf.st_size);
				ft_printf("\n");
			}
		}
	closedir(test);
	}
}
int main(void)
{
	recur_chiotte(".");
}
