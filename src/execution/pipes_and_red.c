/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_and_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:11:49 by hmzah             #+#    #+#             */
/*   Updated: 2021/04/15 16:13:09 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

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

// void	do_redirections(t_vector *red)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < red->length)
// 	{
// 		if (!word)
// 		{
// 			if (red[i].array->left_fd)
// 		}
// 	}
// }

int		do_pipes_and_red(int i, int len, t_vector *red)
{
	static int	fd = -1;

	if (fd != -1)
		fd = manage_pipes(fd);
	if (i + 1 < len)
		fd = manage_pipes(fd);
	if (red)
		len++;
	// 	do_redirections(red);
	return (fd);
}