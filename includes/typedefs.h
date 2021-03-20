/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:18:55 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/20 16:15:24 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef enum	e_token_type {
	START,
	WORD,
	IO_NUMBER,
	GREAT,
	ANDGREAT,
	DGREAT,
	ANDDGREAT,
	LESS,
	DLESS,
	GREATAND,
	LESSAND,
	GREATANDDASH,
	LESSANDDASH,
	PIPE,
	OROR,
	ANDAND,
	SEMI,
	AMPERSAND,
	NEWLINE
}				t_token_type;

typedef enum	e_cmd_type
{
	SIMPLE_CMD,
	PIPE_SEQ,
	LOGIC_SEQ
}				t_cmd_type;

/*
** void *command = switch(type):
** 	type = SIMPLE_CMD ==> t_simple_command
**	type = PIPE_SEQ ==> t_pipe_sequence
**	type = LOGIC_SEQ ==> t_logic_sequence
*/
typedef struct	s_command
{
	t_cmd_type	type;
	t_bool		is_background_job;
	void		*command;
}				t_command;

/*
**
** - right_fd:
**  if type == GREATAND || type == LESSAND
** 	 switch(str_is_number(right_fd)):
**    TRUE => right_fd is an io_number
**    FALSE => right_fd is a filename
**  else if type == DLESS
**   right_fd is an io_number
**  else
**   right_fd is a filename
*/
typedef struct	s_redirection
{
	t_token_type	type;
	int				left_fd;
	char			*righ_fd;
}				t_redirection;

/*
** t_vector *args [char *]
** t_vector *redirections [t_redirection]
*/
typedef struct	s_simple_command
{
	t_vector	*args;
	t_vector	*redirections;
}				t_simple_command;

/*
** t_vector *commands [t_simple_command]
*/
typedef struct	s_pipe_sequence
{
	t_vector	*commands;
}				t_pipe_sequence;

/*
** t_vector *commands [t_command]
** t_vector	*logic_ops [t_token_type] 
*/
typedef struct	s_logic_sequence
{
	t_vector	*commands;
	t_vector	*logic_ops;
}				t_logic_sequence;

#endif
