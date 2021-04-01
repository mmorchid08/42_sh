/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forty_two_sh.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:17:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 18:50:53 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORTY_TWO_SH_H
# define FORTY_TWO_SH_H

# include "libft.h"
# include "typedefs.h"
# include "src/errors/errors.h"

extern	int
g_exit_status;
extern int
g_term_fd;
extern t_vector
*g_job_list;
extern t_vector
*g_stopped_jobs;


/*
** ================================ jobs =======================================
*/

t_job		*new_job(t_bool is_background);
int			wait_job(t_job *job);
void		init_jobs(void);
void		add_process_to_job(t_job *job, pid_t pid);
t_process	*get_process_from_job(t_job *job, pid_t pid);
void		remove_process_from_job(t_job *job, pid_t pid);
void		add_to_job_list(t_job *job);
t_job		*get_job_by_id(uint32_t id);
void		remove_from_job_list(uint32_t job_id);
void		update_stopped_jobs(t_job *job);


/*
** ============================= end jobs ======================================
*/

/*
** ================================ execution ==================================
*/

void		execute_commands(t_vector *commands);
int			execute_simple_cmd(t_simple_command *simple_cmd,
				t_bool is_background, t_bool is_interactive);
int			execute_pipe_seq(t_pipe_sequence *pipe_seq, t_bool is_background,
				t_bool is_interactive);
int			get_exit_code(int wait_status);

/*
** ============================= end execution =================================
*/


#endif
