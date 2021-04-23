/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:01:08 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/31 11:01:18 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_parse_pipe	*parse_pipe_init(t_vector *tokens_vec)
{
	t_parse_pipe *ptr;

	ptr = (t_parse_pipe*)ft_malloc(sizeof(t_parse_pipe));
	ptr->pipe_cmd = (t_pipe_sequence*)ft_malloc(sizeof(t_pipe_sequence));
	ptr->pipe_cmd->commands = vector_init(sizeof(t_simple_command), free);
	ptr->cmd_tokens = vector_init(sizeof(t_token), NULL);
	ptr->tokens = (t_token*)tokens_vec->array;
	ptr->tokens_len = tokens_vec->length;
	ptr->tokens_index = 0;
	ptr->current_token = ptr->tokens[ptr->tokens_index];
	return (ptr);
}

static void			parse_pipe_advance(t_parse_pipe *p_p)
{
	++(p_p->tokens_index);
	p_p->current_token = p_p->tokens[p_p->tokens_index];
}

static void			parse_pipe_free_all(t_parse_pipe *p_p)
{
	vector_free(p_p->pipe_cmd->commands);
	free(p_p->pipe_cmd);
	vector_free(p_p->cmd_tokens);
	ft_bzero(p_p, sizeof(t_parse_pipe));
	free(p_p);
}

static void			parse_pipe_clean(t_parse_pipe *p_p)
{
	vector_free(p_p->cmd_tokens);
	ft_bzero(p_p, sizeof(t_parse_pipe));
	free(p_p);
}

static int			add_simple_command(t_parse_pipe *p_p)
{
	t_simple_command *simple_cmd;

	simple_cmd = parse_simple_cmd(p_p->cmd_tokens);
	if (simple_cmd == NULL)
	{
		parse_pipe_free_all(p_p);
		return (EXIT_FAILURE);
	}
	vector_push(p_p->pipe_cmd->commands, simple_cmd);
	vector_free(p_p->cmd_tokens);
	p_p->cmd_tokens = vector_init(sizeof(t_token), NULL);
	return (EXIT_SUCCESS);
}

static void				push_cmd_token(t_parse_pipe *p_p)
{
	t_token *token;

	token = token_dup(p_p->current_token);
	vector_push(p_p->cmd_tokens, token);
	free(token);
}

t_pipe_sequence		*parse_pipe(t_vector *tokens_vec)
{
	t_parse_pipe	*p_p;
	t_pipe_sequence *pipe_cmd;

	p_p = parse_pipe_init(tokens_vec);
	while (p_p->tokens_index < p_p->tokens_len)
	{
		if (p_p->current_token.type == PIPE)
		{
			if (add_simple_command(p_p) == EXIT_FAILURE)
				return (NULL);
		}
		else
			push_cmd_token(p_p);
		parse_pipe_advance(p_p);
	}
	if (add_simple_command(p_p) == EXIT_FAILURE)
		return (NULL);
	pipe_cmd = p_p->pipe_cmd;
	pipe_cmd->job_name = get_job_name(tokens_vec);
	parse_pipe_clean(p_p);
	return (pipe_cmd);
}
