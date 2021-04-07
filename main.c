#include "forty_two_sh.h"
#include <sys/types.h>
#include <sys/wait.h>

/*
**	Structures.
*/

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_t;

/*
**	End of structures.
*/

/*
**	Global Variables.
*/

int			g_exit_status;
t_t		*g_env;

/*
**	End of Global Variables.
*/

/*
**	t_t *env to array
*/

int			lst_size(t_t *env)
{
	int		i;
	t_t		*fresh;

	i = 0;
	fresh = env;
	while (fresh != NULL)
	{
		i++;
		fresh = fresh->next;
	}
	return (i);
}

char		**env_to_array(t_t *env)
{
	t_t		*tail;
	char	**a_env;
	int		i;
	char	*str_one;
	char	*str_two;

	a_env = (char **)ft_memalloc(sizeof(char *) * (lst_size(env) + 1));
	a_env[lst_size(env)] = NULL;
	tail = env;
	i = 0;
	while (tail)
	{
		if (ft_strcmp(tail->key, "?"))
		{
			str_one = ft_strjoin(tail->key, "=");
			str_two = ft_strjoin(str_one, tail->value);
			a_env[i++] = ft_strdup(str_two);
			ft_strdel(&str_one);
			ft_strdel(&str_two);
		}
		tail = tail->next;
	}
	return (a_env);
}


/*
**	Init env
*/

void	split_them(t_t **tail, char **env, int index)
{
	char	**temp_var;

	temp_var = ft_strsplit(env[index], '=');
	(*tail)->key = NULL;
	(*tail)->value = NULL;
	if (temp_var[0])
		(*tail)->key = ft_strdup(temp_var[0]);
	else
		(*tail)->key = ft_strdup("");
	if (temp_var[1])
		(*tail)->value = ft_strdup(temp_var[1]);
	else
		(*tail)->value = ft_strdup("");
	ft_free_strings_array(temp_var);
}

t_t		*init_env(char **env)
{
	t_t	*actual_env;
	t_t	*tail;
	int	i;

	tail = NULL;
	actual_env = NULL;
	i = -1;
	if (!(actual_env = (t_t *)ft_memalloc(sizeof(t_t))) || env[0] == NULL)
		return (NULL);
	actual_env->next = NULL;
	tail = actual_env;
	while (env[++i])
	{
		split_them(&tail, env, i);
		if (!(tail->next = (t_t *)ft_memalloc(sizeof(t_t))))
			return (NULL);
		tail = tail->next;
	}
	tail->key = ft_strdup("?");
	tail->value = ft_itoa(g_exit_status);
	tail->next = NULL;
	return (actual_env);
}

/*
**	End of init env
*/

/*
**	Remove quoting.
*/

void	handle_quotes(char c, int *balance)
{
	if (c == '\"' && *balance == 0)
		*balance = 2;
	else if (c == '\'' && *balance == 0)
		*balance = 1;
	else if (c == '\"' && *balance == 2)
		*balance = 0;
	else if (c == '\'' && *balance == 1)
		*balance = 0;
}

void	remove_quotes(char **str)
{
	int		i;
	int		len;
	int		b;
	int		j;

	i = 0;
	len = ft_strlen(*str);
	b = 0;
	while (i < len)
	{
		if ((*str)[i] == '\'' || (*str)[i] == '"')
			handle_quotes((*str)[i], &b);
		if (((*str)[i] == '"' && (b == 0 || b == 2)) ||
			((*str)[i] == '\'' && (b == 0 || b == 1)))
		{
			j = i - 1;
			while (++j < len)
				(*str)[j] = (*str)[1 + j];
			len--;
			i--;
		}
		i++;
	}
}

/*
**	End of remove quoting
*/

/*
**	Tools.
*/

char		*ft_lsstsearch(t_t *env, char *to_search)
{
	t_t		*fresh;

	fresh = env;
	while (fresh != NULL)
	{
		if (!(ft_strcmp(fresh->key, to_search)))
		{
			if (!ft_strcmp(fresh->key, "?"))
			{
				ft_strdel(&fresh->value);
				fresh->value = ft_itoa(g_exit_status);
			}
			return (fresh->value);
		}
		fresh = fresh->next;
	}
	return (NULL);
}

/*
**	End of tools.
*/

/*
**	In this part you will find certain functions to manage full_path;
*/

int		check_file(char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	return (0);
}

char	*brute_force(char *cmd, char *path_env)
{
	char	**ab;
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!path_env || !(ab = ft_strsplit(path_env, ':')))
		return (ft_strdup(cmd));
	i = -1;
	tmp = NULL;
	tmp2 = NULL;
	while (ab[++i])
	{
		tmp = ft_strjoin(ab[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (check_file(tmp2))
		{
			ft_free_strings_array(ab);
			return (tmp2);
		}
		free(tmp2);
	}
	ft_free_strings_array(ab);
	return (ft_strdup(cmd));
}

char	*get_full_path(char *cmd, t_t *env)
{
	char	*full_path;

	if (!(check_file(cmd) && cmd[0] != '.' &&
		cmd[0] != '/'))
		full_path = brute_force(cmd, ft_lsstsearch(env, "PATH"));
	else
		full_path = ft_strdup(cmd);
	return (full_path);
}

/*
** End of full_path part;
*/

int			execute_simple_cmd(t_simple_command *simple, t_bool is_background,
	t_bool is_interactive)
{
	pid_t		pid;
	char		*full_path;
	char		**env;
	char		**args;
	int			i;

	args = (char **)simple->args->array;
	full_path = get_full_path(args[0], g_env);
	env = env_to_array(g_env);
	i = 0;
	is_background = 99;
	is_interactive = 0;
	while (args[i])
		remove_quotes(&args[i++]);
	if ((pid = fork()) == -1)
	{
		ft_printf(2, "Forking error\n");
		return (1);
	}
	else if (pid)
		wait(0);
	else if (pid == 0)
	{
		if (execve(full_path, args, env) == -1)
		{
			ft_printf(2, "Error executing\n");
			exit(0);
		}
	}
	return (pid);
}

void		backups(int f)
{
	static int	stdii;
	static int	stdou;
	static int	stder;
	
	if (f == 1)
	{
		stdii = dup(0);
		stdou = dup(1);
		stder = dup(2);
	}
	else
	{
		dup2(stdii, 0);
		dup2(stdou, 1);
		dup2(stder, 2);
		if (f == 3)
		{
			close(stdii);
			close(stdou);
			close(stder);
		}
	}
}

int			manage_pipes(int i, int len)
{
	static	int		fd[2];

	if (i + 1 != len)
	{
		if (pipe(fd) == -1)
			exit(0);
		dup2(fd[1], 1);
		close(fd[1]);
		return (fd[0]);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		return (-1);
	}
}

int			execute_pipe_seq(t_pipe_sequence *command)
{
	t_simple_command	*s_cmd;
	char				**args;
	int					i;
	int					fd;
	char				**env;
	int					pid;
	char				*full_path;

	i = 0;
	fd = -1;
	s_cmd = (t_simple_command *)command->commands->array;
	while (i < (int)command->commands->length)
	{
		args = (char **)s_cmd[i].args->array;
		full_path = get_full_path(args[0], g_env);
		env = env_to_array(g_env);
		fd = manage_pipes(i, (int)command->commands->length); // pipe and fd things
		if ((pid = fork()) == -1) // error
		{
			ft_printf(2, "Error forking\n");
			return (-1);
		}
		else if (pid == 0) // child process
		{
			if (fd != -1) //pipe and fd things
				close(fd);
			if (execve(full_path, args, env))
			{
				ft_printf(2, "Error\n");
				exit(0);
			}
		}
		else // parent process
		{
			backups(2); //pipes and fd things;
			if (i + 1 == (int)command->commands->length)
				while (wait(0) > 0)
					;
		}
		i++;
	}
	return (1);
}

void		execute_commands(t_vector *vec)
{
	t_command *const	cmds_array = vec->array;
	int					i;

	i = 0;
	backups(1);
	while (i < (int)vec->length)
	{
		if (cmds_array[i].type == SIMPLE_CMD)
			g_exit_status = execute_simple_cmd(cmds_array[i].command,
			cmds_array[i].is_background_job, TRUE);
		if (cmds_array[i].type == PIPE_SEQ)
			g_exit_status = execute_pipe_seq(cmds_array[i].command); // you can add the variables u need.
		i++;
	}
	backups(3);
}

int			main(int ac, char *av[], char *envp[])
{
	char		*cmd;
	t_vector	*vec;

	(void)envp;
	signal(SIGTSTP, SIG_IGN);
	g_env = init_env(envp);
	if (ac == 3 && ft_strcmp(av[1], "-c") == 0)
		(void)parser(av[2]);
	else if (ac == 1)
	{
		while (42)
		{
			ft_printf(1, "$> ");
			get_next_line(0, &cmd);
			vec = parser(cmd);
			if (vec)
				execute_commands(vec);
			ft_strdel(&cmd);
		}
	}
	else
		ft_printf(2, "Error\nusage: ./21sh [-c command]\n");
	return (0);
}