/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forty_two_sh.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:17:07 by ylagtab           #+#    #+#             */
/*   Updated: 2021/05/02 16:18:49 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORTY_TWO_SH_H
# define FORTY_TWO_SH_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

# include "../libft/libft.h"
# include "constants.h"
# include "typedefs.h"
# include "../src/errors/errors.h"
# include "../src/parser/parser.h"
# include "../src/expansion/expansion.h"
# include "../src/env/env.h"
# include "../src/builtins/builtins.h"
# include "../readline/readline.h"

void		del_token(void *element);
void		del_redirection(void *element);
void		del_var(void *element);

extern	t_vector
*g_shell_env;
extern	int
g_exit_status;
extern	int
g_term_fd;
extern	t_vector
*g_job_list;
extern	t_vector
*g_stopped_jobs;
extern	t_t
*g_hash;
extern	t_bool
g_is_job_enabled;

/*
** ================================ jobs =======================================
*/

t_job		*new_job(t_bool is_background, char *job_name);
int			wait_job(t_job *job);
void		init_jobs(void);
void		add_process_to_job(t_job *job, pid_t pid);
t_process	*get_process_from_job(t_job *job, pid_t pid);
void		remove_process_from_job(t_job *job, pid_t pid);
void		add_to_job_list(t_job *job);
t_job		*get_job_by_id(uint32_t id);
void		remove_from_job_list(uint32_t job_id);
void		update_stopped_jobs(t_job *job);
void		update_job_state(t_job *job, pid_t pid, int wait_status);
void		update_job(t_job *job);
void		update_all_jobs(void);
void		print_job(t_job *job, t_job_print_mode mode,
				t_special_jobs *special_jobs);
void		notify_job_state(void);
t_job		*get_previous_job(void);
t_job		*get_current_job(void);
t_job		*get_job_by_selector(char *job_selector);
int			execute_job(t_vector *pids_vec, char *job_name,
				t_bool is_background);
int			ft_fg(char **args);
int			ft_bg(char **args);
int			ft_jobs(char **args);
void		set_process_group(pid_t pid, pid_t *pgid, t_bool is_background);
t_vector	*pid2vec(pid_t pid);

/*
** ============================= end jobs ======================================
*/

/*
** ================================ execution ==================================
*/

int			do_redirections(t_vector *red);
int			ft_error(char *str);
int			do_pipes_and_red(int i, int len, t_vector *red);
char		*get_full_path(char *cmd);
void		handle_quotes(char c, int *balance);
void		remove_quotes(char **str);
void		execute_commands(t_vector *commands);
int			execute_simple_cmd(t_simple_command *simple_cmd,
				t_bool is_background);
int			execute_logic_seq(t_logic_sequence *logic_seq,
				t_bool is_background);
int			execute_pipe_seq(t_pipe_sequence *pipe_seq, t_bool is_background);
int			get_exit_code(int wait_status);
int			wait_children(pid_t ret_pid);
void		execute_builtins(char **cmd, t_vector *red);
int			check_builtins(char *cmd);
void		remove_quotes_from_args(char **args);
void		reset_signals(void);
int			manage_pipes(int i);

/*
** ============================= end execution =================================
*/

int			do_tree(char *word, char *flag);
int			do_tests(int i, int is_not, char **cmd);
int			is_correct_path(char *path, int print_error);
char		*concat_path_with_cdpath(char *path);
int			ft_cd(char **cmd);
int			get_next_line(int fd, char **line);
void		backups(int f);
int			check_nbr(char *str, t_bool stat, int f);
int			jhin(char **cmd);
int			check_is_not(int ret, int is_not);
int			ft_test(char **cmd);
int			ft_echo(char **cmd, t_vector *red);
void		print_hash(t_t *root);
char		*find_key_in_hash(t_t *root, char *key);
void		free_hash(t_t **root);
void		ft_type(char **cmd);
t_t			*insert_name(t_t *root, char *key, char *value);
int			export(char **av);
void		ft_exit(char **cmd);

char		*ft_strnjoin(char **strings, int n);
int			ft_isinstr(char c, const char *s);
char		*ft_skip_unitl_char(const char *str, const char *compare,
				int (*f)(int));

/*
**		free functions
*/

void		del_token(void *element);
void		del_redirection(void *element);
void		del_var(void *element);

/*
** Prompt
*/

char		*prompt_1(void);

/*
** read
*/

char		*read_cmd_multiline(void);

/*
** Utils
*/

t_bool		is_quote(char c);
t_bool		quote_type(char c);

int			sh_system(char *line);

#endif
