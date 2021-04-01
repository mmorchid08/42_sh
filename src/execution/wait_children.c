/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:54:43 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/01 10:59:20 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

int	wait_children(pid_t ret_pid)
{
	pid_t	pid;
	int		wait_status;

	while ((pid = waitpid(-1, &wait_status, 0)) != -1)
	{
		if (pid == ret_pid)
			
	}
}
