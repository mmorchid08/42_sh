#include "forty_two_sh.h"

void	do_special_char(char c)
{
	if (c == 'a')
		ft_printf(1, "\a");
	else if (c == 'b')
		ft_printf(1, "\b");
	else if (c == 'c')
		ft_printf(1, "c");
	else if (c == 'f')
		ft_printf(1, "\f");
	else if (c == 'n')
		ft_printf(1, "\n");
	else if (c == 'r')
		ft_printf(1, "\r");
	else if (c == 't')
		ft_printf(1, "\t");
	else if (c == 'v')
		ft_printf(1, "\v");
	else
		ft_printf(1, "%c", c);
}

void	do_printing(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			do_special_char(str[i + 1]);
		else
			ft_printf(1, "%c", str[i]);
		i++;
	}
}

int	ft_echo(char **str)
{
	int	i;
	int	opt;

	i = 1;
	opt = 0;
	if (!str[i])
	{
		ft_printf(1, "\n");
		return (0);
	}
	while (!ft_strcmp("-n", str[i]))
	{
		opt = 1;
		i++;
	}
	while (str[i])
	{
		do_printing(str[i]);
		i++;
		if (str[i])
			ft_printf(1, " ");
	}
	if (opt == 0)
		ft_printf(1, "\n");
	return (0);
}
