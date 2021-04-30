/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_and_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/30 03:50:33 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"
#include <dirent.h>

int	manage_pipes(int i)
{
	static int		fd[2];

	if (i == -1)
	{
		if (pipe(fd) == -1)
			exit(0);
		dup2(fd[1], 1);
		close(fd[1]);
		return (fd[0]);
	}
	else if (i == 2)
	{
		return (close(fd[0]));
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		return (-1);
	}
}

int	ft_error(char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (access(str, F_OK) == 0)
	{
		if (dir)
			ft_printf(2, "42sh: %s: Is a directory\n", str);
		else
			ft_printf(2, "42sh: %s: Permission denied\n", str);
	}
	else
		ft_printf(2, "42sh: %s: No such file or directory\n", str);
	closedir(dir);
	return (-1);
}

int	do_pipes_and_red(int i, int len, t_vector *red)
{
	static int	fd = -1;

	if (fd != -1)
		fd = manage_pipes(fd);
	if (i + 1 < len)
		fd = manage_pipes(-1);
	if (red)
	{
		if (do_redirections(red) == -1)
			return (1);
	}
	return (fd);
}
