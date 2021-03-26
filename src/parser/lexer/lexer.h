/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:53:54 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/26 09:21:06 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "forty_two_sh.h"

extern char	*g_tokens_to_string[];

t_vector	*lexer(char *line, t_bool enable_alias_subtitution);
void		lexer_print_tokens(t_vector *tokens_vec);
void		lexer_add_newline_token(t_vector *tokens);
t_bool		lexer_is_redirection(t_token_type type);
t_bool		lexer_is_separator(t_token_type type);
t_bool		lexer_is_and_or(t_token_type type);

#endif
