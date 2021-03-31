/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:22:43 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/30 14:02:31 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	do_pipes(int f)
{
	static int	fd[2];

	if (f == 1)
	{
		if (pipe(fd) == -1)
			; // Error;
		dup2(fd[1], 1);
		close(fd[1]);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
	}
}

int		execute_pipe_seq(t_vector *vec, t_bool is_job, t_bool idk)
{
	char	**pip;
	int		i;

	i = 0;
	while (i < vec->capacity) //vec[i]
	{
		pip = (char **)&vec->array;
		/*
		**	Couldn't know how to do it.
		**	If the current vector isn't the last.
		**	Then open pipes. Else close.
		*/
		(i + 1 < vec->capacity) ? do_pipes(0) : do_pipes(1);
		// TODO: Error managing.
		execute_simple_cmd(vec->array, is_job);
		i++; //Will figure out in the morning
	}
}