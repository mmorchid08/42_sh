/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_and_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/27 10:32:55 by hmzah            ###   ########.fr       */
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
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		return (-1);
	}
}

void	ft_error(char *str)
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
	
}

int		open_files_for_red(t_redirection *red)
{
	int	fd;

	fd = -1;
	if (red->type == GREAT || red->type == GREATAND || red->type == ANDGREAT)
		fd = open(red->righ_fd, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (red->type == DGREAT)
		fd = open(red->righ_fd, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (red->type == LESS)
		if ((fd = open(red->righ_fd, O_RDWR)) == -1)
		{
			ft_error(red->righ_fd);
			return (-1);
		}
	if (red->type == GREATAND || red->type == LESSAND)
		dup2(fd, 2);
	if (red->type == LESS || red->type == LESSAND)
		dup2(fd, 0);
	else if (red->left_fd != -1)
		dup2(fd, red->left_fd);
	else if (!(red->type == DLESS))
		dup2(fd, 1);
	if (fd != -1)
		close(fd);
	return (1);
}

int		str_is_number(char *str, t_token_type type)
{
	int	i;

	i = -1;
	if (type != GREATANDDASH && type != LESSANDDASH)
	{
		while (str[++i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
		}
	}
	return (1);
}

int	do_redirections(t_vector *red)
{
	int				i;
	t_redirection	*redi;
	int				fd;

	i = -1;
	while (++i < (int)red->length)
	{
		redi = (t_redirection *)red[i].array;
		if (redi->type == DLESS
			|| (redi->type == GREATAND && str_is_number(redi->righ_fd, redi->type))
			|| (redi->type == LESSAND && str_is_number(redi->righ_fd, redi->type))
			|| redi->type == GREATANDDASH || redi->type == LESSANDDASH)
		{
			if (redi->left_fd == -1)
				fd = 1;
			else
				fd = redi->left_fd;
			if (redi->left_fd == -1 && (redi->type == GREATAND || redi->type == GREATANDDASH))
				redi->left_fd = 1;
			if (redi->type == GREATANDDASH || redi->type == LESSANDDASH)
				close(redi->left_fd);
			else if (dup2(ft_atoi(redi->righ_fd), fd) == -1)
				return (-1);
		}
		else
			if (open_files_for_red(redi) == -1)
				return (-1);
	}
	return (1);
}


int		do_pipes_and_red(int i, int len, t_vector *red)
{
	static int	fd = -1;

	if (fd != -1)
		fd = manage_pipes(fd);
	if (i + 1 < len)
		fd = manage_pipes(fd);
	if (red)
	{
		if (do_redirections(red) == -1)
		{
			return (1);
		}
	}
	return (fd);
}