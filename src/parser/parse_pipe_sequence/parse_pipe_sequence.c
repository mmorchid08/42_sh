/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_sequence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:01:08 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/25 19:14:05 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

t_parse_pipe	*parse_pipe_sequence(t_vector *tokens_vec)
{
	t_parse_pipe *ptr;

	ptr = (t_parse_pipe*)fr_malloc(sizeof(t_parse_pipe));
	ptr->cmd = (t_pipe_sequence*)ft_malloc(sizeof(t_pipe_sequence));
	ptr->cmd->commands = vector_init(sizeof(t_simple_command), free);
	ptr->simple_cmd_tokens = vector_init(sizeof(t_token), free);
	ptr->simple_cmd = NULL;
	ptr->tokens = (t_token*)tokens_vec->array;
	ptr->tokens_len = tokens_vec->length;
	ptr->tokens_index = 0;
	ptr->current_token = ptr->tokens[ptr->tokens_index];
}

void	parse_pipe_advance(t_parse_pipe *p_p)
{
	++(p_p->tokens_index);
	p_p->current_token = p_p->tokens[p_p->tokens_index];
}

void	parse_pipe_free_all(t_parse_pipe *p_p)
{
	vector_free(p_p->cmd->commands);
	free(p_p->cmd);
	vector_free(p_p->simple_cmd_tokens);
	ft_bzero(p_p, sizeof(t_parse_pipe));
	free(p_p);
}

int		parse_pipe_sequence(t_vector *tokens_vec)
{
	t_parse_pipe	*p_p;
	t_pipe_sequence *cmd;

	p_p = parse_pipe_init(tokens_vec);
	while (p_p->tokens_index < p_p->tokens_len)
	{
		if (p_p->current_token.type == PIPE)
		{
			p_p->simple_cmd = parse_simple_command(p_p->simple_cmd_tokens);
			if (p_p->simple_cmd == NULL)
			{
				parse_pipe_free_all(p_p);
				return (NULL);
			}
		}
		vector_push(p_p->simple_cmd_tokens, &(p_p->current_token));
		parse_pipe_advance(p_p);
	}
}
