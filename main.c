#include "forty_two_sh.h"
#include <sys/types.h>
#include <sys/wait.h>

void		free_shit(void *elem)
{
	free(elem);
}

t_simple_command	*parse_simple_cmd(char *input)
{
	t_simple_command	*cmd;
	char				**str;
	int					i;

	cmd = (t_simple_command *)ft_malloc(sizeof(t_simple_command));
	cmd->args = vector_init(sizeof(char *), free);
	cmd->redirections = NULL;
	str = ft_strsplit(input, ' ');
	i = 0;
	while (str[i])
		vector_push(cmd->args, &str[i++]);
	vector_push(cmd->args, (char *[]){NULL});
	return (cmd);
}

t_command	*fast_parser(char *input)
{
	t_command	*cmd;

	cmd = (t_command *)ft_malloc(sizeof(t_command));
	cmd->type = SIMPLE_CMD;
	cmd->is_background_job = false;
	cmd->command = parse_simple_cmd(input);
	return (cmd);
}

int			ft_temperror(char *str)
{
	ft_printf(2, "%s", str);
	return (EXIT_FAILURE);
}

int		execute_simple_cmd(char **str, char **env)
{
	int		pid;
	int		status;

	if ((pid = fork()) == -1)
		return (ft_temperror("Could not fork.\n"));
	else if (pid == 0)
	{
		if (execve(str[0], str, env) == -1)
			return (ft_temperror("Could not execute.\n"));
		exit(1);
	}
	else
		while (waitpid(pid, &status, 0) > 0)
			;
	return (EXIT_SUCCESS);
}

void		execution_testing(t_vector *vec, char **env)
{
	t_command			**tail;
	t_simple_command	*cc;
	t_vector			*lol;
	char				**str;
	int					i;

	tail = (t_command **)vec->array;
	i = 0;
	while (tail[i])
	{
		if (tail[i]->type == SIMPLE_CMD)
		{
			cc = (t_simple_command *)tail[i]->command;
			lol = cc->args;
			str = (char **)lol->array;
			execute_simple_cmd(str, env);
		}
		i++;
	}
}

int			main(int ac, char **av, char **env)
{
	char		*input;
	t_vector	*tcmd_vec;		//Vector for t_command *

	input = NULL;
	(void)ac;
	(void)av;
	while (42)
	{
		ft_printf(1, "$> ");
		tcmd_vec = vector_init(sizeof(t_command), free_shit);
		get_next_line(0, &input);
		t_command	*pp;
		t_command	*bg;
		bg = NULL;
		pp = fast_parser(input);
		vector_push(tcmd_vec, &pp);
		vector_push(tcmd_vec, &bg);
		if (tcmd_vec)
			execution_testing(tcmd_vec, env);
	}
}