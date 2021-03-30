/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:27:57 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/30 13:50:20 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static void	print_simple_cmd(t_simple_command *cmd)
{
	t_var			*assigns;
	char			**args;
	t_redirection	*reds;
	size_t			i;

	ft_printf(1, "\n- simple_command:");
	ft_printf(1, "\n-- assignments: ");
	i = 0;
	assigns = cmd->assignments->array;
	while (i < cmd->assignments->length)
	{
		ft_printf(1, "(%s = %s) ", assigns[i].key, assigns[i].value);
		++i;
	}
	ft_printf(1, "\n-- args: ");
	i = 0;
	args = cmd->args->array;
	while (i < cmd->args->length)
	{
		ft_printf(1, "%s ", args[i]);
		++i;
	}
	ft_printf(1, "\n-- redirections: ");
	i = 0;
	reds = cmd->redirections->array;
	while (i < cmd->redirections->length)
	{
		ft_printf(1, "(%d %s %s) ", reds[i].left_fd,
			g_tokens_to_string[reds[i].type], reds[i].righ_fd);
		++i;
	}
	ft_printf(1, "\n");
}

void	print_commands(t_vector *commands_vec)
{
	t_command	*commands;
	size_t		i;

	commands = (t_command*)commands_vec->array;
	i = 0;
	while (i < commands_vec->length)
	{
		if (commands[i].type == SIMPLE_CMD)
			print_simple_cmd(commands[i].command);
		++i;
	}
}
