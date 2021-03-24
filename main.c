#include "forty_two_sh.h"
#include "libft.h"

void	free_shit(void *ptr)
{
	free(ptr);
}

int		main(void)
{
	t_vector			*vec;
	char				**tvc;
	t_command			*cmd;
	t_command			*lol;
	t_command			**tst;
	t_simple_command	*sm;
	t_simple_command	**tts;
	char				*com;
	char				*arg;
	int					i;

	com = ft_strdup("/bin/ls");
	arg = ft_strdup("-laF");
	lol = NULL;
	sm = (t_simple_command *)ft_malloc(sizeof(t_simple_command));
	sm->args = vector_init(sizeof(char *), free_shit);
	sm->redirections = NULL;
	vector_push(sm->args, &com);
	vector_push(sm->args, &arg);
	cmd = (t_command *)ft_malloc(sizeof(t_command));
	cmd->type = SIMPLE_CMD;
	cmd->is_background_job = 0;
	cmd->command = &sm;
	vec = vector_init(sizeof(t_command *), free_shit);
	vector_push(vec, &cmd);
	vector_push(vec, &lol);
	ft_printf(1, "Finished Filling\n");
	ft_printf(1, "Testing time : \n");
	tst = (t_command **)vec->array;
	i = 0;
	while (tst[i])
	{
		ft_printf(1, "The type of this command is : %d\n", tst[i]->type);
		ft_printf(1, "Now printing the command and its args : \n");
		if (tst[i]->type == SIMPLE_CMD)
		{
			tts = (t_simple_command **)(tst[i]->command);
			tvc = (char **)tts[i]->args;
			int i = 0;
			while (tvc[i])
				ft_printf(1, "tvc is : %s\n", tvc[i++]);
		}
		i++;
	}
}