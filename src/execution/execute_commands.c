/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:22:43 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/06 14:03:00 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "forty_two_sh.h"

void	execute_commands(t_vector *commands)
{
	t_command *const	cmds_array = commands->array;
	int					i;

	i = 0;
	while (i < commands->length)
	{
		if (cmds_array[i].type == LOGIC_SEQ)
			g_exit_status = execute_logic_seq(&cmds_array[i].command,
					cmds_array[i].is_background_job);
		else if (cmds_array[i].type == PIPE_SEQ)
			g_exit_status = execute_pipe_seq(&cmds_array[i].command,
					cmds_array[i].is_background_job, TRUE);
		else if (cmds_array[i].type == SIMPLE_CMD)
			g_exit_status = execute_simple_cmd(&cmds_array[i].command,
					cmds_array[i].is_background_job, TRUE);
		i++;
	}
}
