/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_complete_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:02:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/30 17:49:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	*get_command_by_type(t_parse_complete *parser)
{
	void *command;

	if (parser->cmd_type == SIMPLE_CMD)
		command = parse_simple_cmd(parser->cmd_tokens);
	else if (parser->cmd_type == PIPE_SEQ)
		command = parse_pipe(parser->cmd_tokens);
	else
		command = parse_and_or(parser->cmd_tokens);
	return (command);
}

int			add_complete_cmd(t_parse_complete *parser)
{
	t_command *cmd;

	cmd = (t_command*)ft_malloc(sizeof(t_command));
	cmd->type = parser->cmd_type;
	cmd->is_background_job = parser->current_token.type == AMPERSAND;
	cmd->command = get_command_by_type(parser);
	if (cmd->command == NULL)
		return (EXIT_FAILURE);
	vector_push(parser->commands, cmd);
	reset_cmd_tokens(parser);
	parser->cmd_type = SIMPLE_CMD;
	return (EXIT_SUCCESS);
}
