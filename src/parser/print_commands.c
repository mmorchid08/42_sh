/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:27:57 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/12 10:55:35 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	print_simple_cmd(t_simple_command *cmd)
{
	t_var			*assigns;
	char			**args;
	t_redirection	*reds;
	size_t			i;

	printf("\n------------------------------------------------");
	printf("\n- simple_command: %s\n", cmd->job_name);
	printf("\n-- assignments: ");
	i = 0;
	assigns = cmd->assignments->array;
	while (i < cmd->assignments->length)
	{
		printf("(%s = %s) ", assigns[i].key, assigns[i].value);
		++i;
	}
	printf("\n-- args: ");
	i = 0;
	args = cmd->args->array;
	while (i < cmd->args->length)
	{
		printf("%s|", args[i]);
		++i;
	}
	printf("\n-- redirections: ");
	i = 0;
	reds = cmd->redirections->array;
	while (i < cmd->redirections->length)
	{
		printf("(%d %s %s) ", reds[i].left_fd,
			g_tokens_to_string[reds[i].type], reds[i].righ_fd);
		++i;
	}
	printf("\n------------------------------------------------\n");
}

void	print_pipe_cmd(t_pipe_sequence *cmd)
{
	t_simple_command	*simple_commands;
	size_t				i;

	printf("\n************************************************");
	printf("\n* pipe_sequence: %s\n", cmd->job_name);
	i = 0;
	simple_commands = cmd->commands->array;
	while (i < cmd->commands->length)
	{
		print_simple_cmd(simple_commands + i);
		++i;
	}
	printf("\n************************************************\n");
}

void	print_logic_cmd(t_logic_sequence *cmd)
{
	t_token_type	*logic_ops;
	size_t			i;

	printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	printf("\n@ logic_sequence: %s\n", cmd->job_name);
	i = 0;
	logic_ops = cmd->logic_ops->array;
	while (i < cmd->logic_ops->length)
	{
		printf("%s ", g_tokens_to_string[logic_ops[i]]);
		++i;
	}
	print_commands(cmd->commands);
	printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void	print_commands(t_vector *commands_vec)
{
	t_command	*commands;
	size_t		i;

	commands = (t_command*)commands_vec->array;
	i = 0;
	while (i < commands_vec->length)
	{
		printf("is_background_job: %d", commands[i].is_background_job);
		if (commands[i].type == SIMPLE_CMD)
			print_simple_cmd(commands[i].command);
		if (commands[i].type == PIPE_SEQ)
			print_pipe_cmd(commands[i].command);
		if (commands[i].type == LOGIC_SEQ)
			print_logic_cmd(commands[i].command);
		++i;
	}
}
