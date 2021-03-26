/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:42:00 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 14:47:43 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internals.h"

static t_parser *parser_init(t_vector *tokens)
{
	t_parser *parser;

	parser = (t_parser*)ft_malloc(sizeof(t_parser));
	parser->commands = vector_init(sizeof(t_command), NULL);
	parser->cmd_tokens = vector_init(sizeof(t_token), free);
	parser->cmd_type = SIMPLE_CMD;
	parser->tokens = (t_token*)tokens->array;
	parser->tokens_len = tokens->length;
	parser->tokens_index = 0;
	parser->current_token = parser->tokens[parser->tokens_index];
	return (parser);
}

static void	parser_clean(t_parser **parser)
{
	ft_bzero(*parser, sizeof(t_parser));
	ft_memdel((void**)parser);
}

void		parser_advance(t_parser *parser)
{
	++(parser->tokens_index);
	parser->current_token = parser->tokens[parser->tokens_index];
}

void		set_cmd_type(t_parser *parser)
{
	t_token_type	token_type;

	token_type = parser->current_token.type;
	if (parser->cmd_type == LOGIC_SEQ)
		return ;
	if (token_type == ANDAND || token_type == OROR)
		parser->cmd_type = LOGIC_SEQ;
	if (token_type == PIPE)
		parser->cmd_type = PIPE_SEQ;
}

int			parse_complete_command(t_parser *parser)
{
	t_command *cmd;

	while (parser->tokens_index < parser->tokens_len)
	{
		if (lexer_is_separator(parser->current_token.type))
			break ;
		vector_push(parser->cmd_tokens, &(parser->current_token));
		set_cmd_type(parser);
	}
	cmd = (t_command*)ft_malloc(sizeof(t_command));
	cmd->type = parser->cmd_type;
	cmd->is_background_job = parser->current_token.type == AMPERSAND;
	if (cmd->type == SIMPLE_CMD)
		cmd->command = parse_simple_cmd(parser->cmd_tokens);
	else if (cmd->type == PIPE_SEQ)
		cmd->command = parse_pipe(parser->cmd_tokens);
	else
		cmd->command = parse_and_or(parser->cmd_tokens);
	if (cmd->command == NULL)
		return (EXIT_FAILURE);
	vector_push(parser->commands, cmd);
	return (EXIT_SUCCESS);
}

void		parser_syntax_error(t_token_type type)
{
	char *suffix;

	suffix = g_tokens_to_string[type];
	ft_strerror(ESYNTAX, NULL, suffix, FALSE);
}

t_vector	*parser(t_vector *tokens)
{
	t_parser	*parser;
	t_vector	*commands;

	parser = parser_init(tokens);
	while (parser->current_token.type != NEWLINE)
	{
		// if (lexer_is_separator(parser->current_token.type))
		// {
		// 	parser_syntax_error(parser->current_token.type);
		// 	parser_clean(&parser);
		// 	return (NULL);
		// }
		if (parse_complete_command(parser) == EXIT_FAILURE)
		{
			parser_clean(&parser);
			return (NULL);
		}
	}
	commands = parser->commands;
	parser_clean(&parser);
	return (commands);
}