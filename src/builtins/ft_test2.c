#include "forty_two_sh.h"

char	check_op(char *op)
{
	if (!ft_strcmp(op, "-eq"))
		return (1);
	if (!ft_strcmp(op, "-ne"))
		return (1);
	if (!ft_strcmp(op, "-gt"))
		return (1);
	if (!ft_strcmp(op, "-ge"))
		return (1);
	if (!ft_strcmp(op, "-lt"))
		return (1);
	if (!ft_strcmp(op, "-le"))
		return (1);
	return (0);
}

int		check_nbr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		do_op(char *fnum, char *op, char *snum)
{
	int	x;
	int	y;

	x = ft_atoi(fnum);
	y = ft_atoi(snum);
	if (!ft_strcmp(op, "-eq"))
		return (x == y ? 0 : 1);
	if (!ft_strcmp(op, "-ne"))
		return (x != y ? 0 : 1);
	if (!ft_strcmp(op, "-gt"))
		return (x > y ? 0 : 1);
	if (!ft_strcmp(op, "-ge"))
		return (x >= y ? 0 : 1);
	if (!ft_strcmp(op, "-lt"))
		return (x < y ? 0 : 1);
	if (!ft_strcmp(op, "-le"))
		return (x <= y ? 0 : 1);
	return (0);
}

int		jhin(char **cmd)
{
	if (!ft_strcmp(cmd[1], "="))
		return ((ft_strcmp(cmd[0], cmd[2])) ? 1 : 0);
	else if (!ft_strcmp(cmd[1], "!="))
		return ((ft_strcmp(cmd[0], cmd[2])) ? 0 : 1);
	else if (check_op(cmd[1]))
	{
		if (!check_nbr(cmd[0]))
		{
			ft_printf(2, "test: integer expression expected: %s\n", cmd[0]);
			return (2);
		}
		else if (!check_nbr(cmd[2]))
		{
			ft_printf(2, "test: integer expression expected: %s\n", cmd[2]);
			return (2);
		}
		return (do_op(cmd[0], cmd[1], cmd[0]));
	}
	ft_printf(2, "test: unkown condition: %s\n", cmd[1]);
	return (2);
}


int		check_is_not(int ret, int is_not)
{
	if (is_not && (ret == 1 || ret == 0))
		return (ret == 1 ? 0 : 1);
	return (ret);
}
