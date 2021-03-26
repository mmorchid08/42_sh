/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:01:31 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 17:16:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_parse_and_or	*and_or_init(t_vector *tokens_vec)
{
	t_parse_and_or *and_or;

	and_or = (t_parse_and_or*)ft_malloc(sizeof(t_parse_and_or));
	and_or->logic_cmd = (t_logic_sequence*)ft_malloc(sizeof(t_logic_sequence));
	and_or->logic_cmd->commands = vector_init(sizeof(t_command), free);
	and_or->logic_cmd->logic_ops = vector_init(sizeof(t_token_type), free);
	and_or->cmd_tokens = vector_init(sizeof(t_token), free);
	and_or->cmd_type = SIMPLE_CMD;
	and_or->tokens = (t_token*)tokens_vec->array;
	and_or->tokens_len = tokens_vec->length;
	and_or->tokens_index = 0;
	and_or->current_token = and_or->tokens[and_or->tokens_index];
	return (and_or);
}

void					and_or_advance(t_parse_and_or *and_or)
{
	++(and_or->tokens_index);
	and_or->current_token = and_or->tokens[and_or->tokens_index];
}

int						and_or_push_command(t_parse_and_or *and_or)
{
	t_command *cmd;

	cmd = (t_command*)ft_malloc(sizeof(t_command));
	cmd->type = and_or->cmd_type;
	cmd->is_background_job = FALSE;
	if (cmd->type == SIMPLE_CMD)
		cmd->command = parse_simple_cmd(and_or->cmd_tokens);
	else if (cmd->type == PIPE_SEQ)
		cmd->command = parse_pipe(and_or->cmd_tokens);
	if (cmd->command == NULL)
		return (EXIT_FAILURE);
	vector_push(and_or->logic_cmd->commands, cmd);
	return (EXIT_SUCCESS);
}

void					and_or_push_logic_op(t_parse_and_or *and_or)
{
	t_token_type type;

	type = and_or->current_token.type;
	vector_push(and_or->logic_cmd->logic_ops, &(type));
}

t_logic_sequence		*parse_and_or(t_vector *tokens_vec)
{
	t_parse_and_or		*and_or;
	t_logic_sequence	*logic_cmd;

	and_or = and_or_init(tokens_vec);
	while (and_or->tokens_index < and_or->tokens_len)
	{
		if (lexer_is_and_or(and_or->current_token.type))
		{
			if (and_or_push_command(and_or) == EXIT_FAILURE)
				return (NULL);
			and_or_push_logic_op(and_or);
		}
		else
		{
			if (and_or->current_token.type == PIPE)
				and_or->cmd_type = PIPE_SEQ;
			vector_push(and_or->cmd_tokens, &(and_or->current_token));
		}
	}
	if (and_or_push_command(and_or) == EXIT_FAILURE)
		return (NULL);
	logic_cmd = and_or->logic_cmd;
	return (logic_cmd);
}