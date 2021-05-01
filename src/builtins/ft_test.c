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

int	check_p(char *word, char *flag, struct stat buf)
{
	if (!ft_strcmp(flag, "-x"))
		return (check_nbr(NULL, (access(word, X_OK) == 0), 2));
	else if (!ft_strcmp(flag, "-r"))
		return (check_nbr(NULL, (access(word, R_OK) == 0), 2));
	else if (!ft_strcmp(flag, "-w"))
		return (check_nbr(NULL, (access(word, W_OK) == 0), 2));
	else if (!ft_strcmp(flag, "-e"))
		return (check_nbr(NULL, (access(word, F_OK) == 0), 2));
	else if (!ft_strcmp(flag, "-s"))
		return (check_nbr(NULL, buf.st_size > 0, 2));
	else if (!ft_strcmp(flag, "-u"))
		return (check_nbr(NULL, buf.st_mode & S_ISUID, 2));
	else if (!ft_strcmp(flag, "-g"))
		return (check_nbr(NULL, buf.st_mode & S_ISGID, 2));
	return (-1);
}

int	check_t(struct stat buf, char *flag)
{
	if (!ft_strcmp(flag, "-b"))
		return (check_nbr(NULL, S_ISBLK(buf.st_mode), 2));
	else if (!ft_strcmp(flag, "-c"))
		return (check_nbr(NULL, S_ISCHR(buf.st_mode), 2));
	else if (!ft_strcmp(flag, "-d"))
		return (check_nbr(NULL, S_ISDIR(buf.st_mode), 2));
	else if (!ft_strcmp(flag, "-f"))
		return (check_nbr(NULL, S_ISREG(buf.st_mode), 2));
	else if (!ft_strcmp(flag, "-L"))
		return (check_nbr(NULL, S_ISLNK(buf.st_mode), 2));
	else if (!ft_strcmp(flag, "-p"))
		return (check_nbr(NULL, S_ISFIFO(buf.st_mode), 2));
	else if (!ft_strcmp(flag, "-S"))
		return (check_nbr(NULL, S_ISSOCK(buf.st_mode), 2));
	return (-1);
}

int	file_part(char *word, char *flag)
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

int	do_tree(char *word, char *flag)
{
	if (!ft_strcmp(flag, "-z"))
		return (check_nbr(NULL, (!ft_strlen(word)), 2));
	else if (!ft_strcmp(flag, "-n"))
		return (check_nbr(NULL, ft_strlen(word), 2));
	return (file_part(word, flag));
}

int	ft_test(char **cmd)
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
	return (do_tests(i, is_not, cmd));
}
