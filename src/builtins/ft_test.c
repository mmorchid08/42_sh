/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:52:38 by hmzah             #+#    #+#             */
/*   Updated: 2021/03/13 11:20:34 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <stdbool.h>

int		check_p(char *word, char *flag, struct stat buf)
{
	if (!ft_strcmp(flag, "-x"))
		return ((access(word, X_OK) == 0) ? 0 : 1);
	else if (!ft_strcmp(flag, "-r"))
		return ((access(word, R_OK) == 0) ? 0 : 1);
	else if (!ft_strcmp(flag, "-w"))
		return ((access(word, W_OK) == 0) ? 0 : 1);
	else if (!ft_strcmp(flag, "-e"))
		return ((access(word, F_OK) == 0) ? 0 : 1);
	else if (!ft_strcmp(flag, "-s"))
		return (buf.st_size > 0 ? 0 : 1);
	else if (!ft_strcmp(flag, "-u"))
		return ((buf.st_mode & S_ISUID) ? 0 : 1);
	else if (!ft_strcmp(flag, "-g"))
		return ((buf.st_mode & S_ISGID) ? 0 : 1);
	return (-1);
}

int		check_t(struct stat buf, char *flag)
{
	if (!ft_strcmp(flag, "-b"))
		return ((!S_ISBLK(buf.st_mode)) ? 1 : 0);
	else if (!ft_strcmp(flag, "-c"))
		return ((!S_ISCHR(buf.st_mode)) ? 1 : 0);
	else if (!ft_strcmp(flag, "-d"))
		return ((!S_ISDIR(buf.st_mode)) ? 1 : 0);
	else if (!ft_strcmp(flag, "-f"))
		return ((!S_ISREG(buf.st_mode)) ? 1 : 0);
	else if (!ft_strcmp(flag, "-L"))
		return ((!S_ISLNK(buf.st_mode)) ? 1 : 0);
	else if (!ft_strcmp(flag, "-p"))
		return ((!S_ISFIFO(buf.st_mode)) ? 1 : 0);
	else if (!ft_strcmp(flag, "-S"))
		return ((!S_ISSOCK(buf.st_mode)) ? 1 : 0);
	return (-1);
}

int		file_part(char *word, char *flag)
{
	struct stat	buf;
	int			ret;

	lstat(word, &buf);
	ret = 0;
	if ((ret == check_p(word, flag, buf)) != false)
		return (ret);
	else if ((ret == check_t(buf, flag)) != false)
		return (ret);
	ft_printf(2, "test: unkown condition: %s\n", flag);
	return (2);
}

int		do_tree(char *word, char *flag)
{
	if (!ft_strcmp(flag, "-z"))
		return (ft_strlen(word) ? 1 : 0);
	else if (!ft_strcmp(flag, "-n"))
		return (ft_strlen(word) ? 0 : 1);
	return (file_part(word, flag));
}

int		ft_test(char **cmd)
{
	int	i;
	int	is_not;

	i = 0;
	is_not = 0;
	while (cmd[i])
		i++;
	if (cmd[1] && !ft_strcmp(cmd[1], "!"))
	{
		is_not = 1;
		cmd = &cmd[2];
		i--;
	}
	else
		cmd = &cmd[1];
	if (i == 1)
		return (check_is_not(1, is_not));
	else if (i == 2 && cmd[0])
		return (check_is_not(0, is_not));
	else if (i == 3)
		return (check_is_not(do_tree(cmd[0], cmd[1]), is_not));
	else if (i == 4)
		return (check_is_not(jhin(cmd), is_not));
	else if (i > 4)
	{
		ft_printf(2, "test: too many arguments\n");
		return (2);
	}
}