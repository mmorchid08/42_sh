/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:18:55 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/15 16:03:29 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef enum	e_token_type {
	START,
	WORD,
	ASSIGNMENT,
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

typedef struct	s_var
{
	char	*key;
	char	*value;
	t_bool	is_exported;
}				t_var;

typedef enum	e_cmd_type
{
	SIMPLE_CMD,
	PIPE_SEQ,
	LOGIC_SEQ
}				t_cmd_type;

typedef struct	s_token
{
	t_token_type	type;
	void			*data;
}				t_token;

/*
** void *command = switch(type):
** 	type = SIMPLE_CMD ==> t_simple_command
**	type = PIPE_SEQ ==> t_pipe_sequence
**	type = LOGIC_SEQ ==> t_logic_sequence
*/
typedef struct s_command
{
	t_cmd_type	type;
	t_bool		is_background_job;
	void		*command;
}				t_command;

/*
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
typedef struct s_redirection
{
	t_token_type	type;
	int				left_fd;
	char			*righ_fd;
}				t_redirection;

/*
** t_vector *args [char *]
** t_vector *redirections [t_redirection]
*/
typedef struct s_simple_command
{
	t_vector	*args;
	t_vector	*redirections;
	t_vector	*assignments;
	char		*job_name;
}				t_simple_command;

/*
** t_vector *commands [t_simple_command]
*/
typedef struct s_pipe_sequence
{
	t_vector	*commands;
	char		*job_name;
}				t_pipe_sequence;

/*
** t_vector *commands [t_command]
*/
typedef struct s_logic_sequence
{
	t_vector	*commands;
	t_vector	*logic_ops;
	char		*job_name;
}				t_logic_sequence;

typedef enum e_run_state
{
	UNDEFINED,
	RUNNING,
	STOPPED,
	COMPLETED
}				t_run_state;

typedef struct s_job
{
	u_int32_t	id;
	t_bool		is_background;
	pid_t		pgid;
	t_run_state	state;
	struct		s_count
	{
		int		running;
		int		stopped;
		int		completed;
	}			count;
	t_vector	*processes;
	t_bool		to_notify;
	pid_t		ret_pid; // TODO give it better name
	int			wait_status;
	char		*job_name;
}				t_job;

typedef struct s_process
{
	t_run_state		state;
	int				wait_status;
	pid_t			pid;
}				t_process;

typedef enum	e_job_print_mode
{
	NORMAL,
	LONG,
	PGID
}				t_job_print_mode;

typedef struct s_special_jobs
{
	t_job	*current;
	t_job	*previous;
}				t_special_jobs;
#endif
