/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:14:47 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/22 09:36:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include "lexer.h"

typedef struct	s_string
{
	char	*data;
	size_t	capacity;
	size_t	length;
}				t_string;

typedef struct	s_lexer
{
	t_vector		*tokens_list;
	t_string		*word;
	char			*line;
	size_t			i;
	t_token_type	token_type;
	char			c;
	char			quote;
	t_bool			backslash;
}				t_lexer;

t_string		*string_new(void);
void			string_push(t_string *str, char c);
char			*string_get_data(t_string *str);
char			lexer_quote_type(char c);
int				lexer_is_space(char c, int quote);
int				lexer_is_number(char c, int quote);
int				lexer_is_operator(char c, int quote);
int				lexer_is_word(char c, int quote);
void			lexer_handle_operator(t_lexer *lex);
void			lexer_handle_io_number(t_lexer *lex);
void			lexer_handle_word(t_lexer *lex);
void			lexer_push_token(t_lexer *lex, t_token_type token_type);
void			lexer_advance(t_lexer *lex, size_t by);
void			lexer_skip_whitespaces(t_lexer *lex);

#endif
