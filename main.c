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
	free_2d(&temp_var);
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

/*
**	End of remove quoting
*/

/*
**	In this part you will find certain functions to manage full_path;
*/

void	check_perm(char *path)
{
	if (access(path, F_OK) == 0)
		mini_printf("%s: Permission Denied.\n", path);
	else
		mini_printf("%s: Command not found.\n", path);
}

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
			free_2d(&ab);
			return (tmp2);
		}
		free(tmp2);
	}
	free_2d(&ab);
	return (ft_strdup(cmd));
}

char	*get_full_path(char *cmd, t_t *env)
{
	char	*full_path;

	if (!(check_file(cmd) && cmd[0] != '.' &&
		cmd[0] != '/') &&
		!check_builtins(cmd))
		full_path = brute_force(cmd, ft_lstsearch(env, "PATH"));
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
	i = 0;
	while (args[i])
	{

	}
}

void		execute_commands(t_vector *vec)
{
	t_command *const	cmds_array = vec->array;
	int					i;

	i = 0;
	while (i < vec->length)
	{
		if (cmds_array[i].type == SIMPLE_CMD)
			g_exit_status = execute_simple_cmd(&cmds_array[i].command,
			cmds_array[i].is_background_job, TRUE);
	}
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
		if (get_next_line(STDIN_FILENO, &cmd) != -1)
		{
			vec = parser(cmd);
			if (vec)
				execute_commands(vec);
		}
	}
	else
		ft_printf(2, "Error\nusage: ./21sh [-c command]\n");
	return (0);
}