#include "forty_two_sh.h"

int	do_special_char(char c)
{
	if (c == 'n')
		ft_putchar('\n');
	else if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 'e' || c == 'E')
		ft_putchar('\e');
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'r')
		ft_putchar('\r');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'v')
		ft_putchar('\v');
	else if (c == '\\')
		ft_putchar('\\');
	else if (c == '0')
		ft_putchar('\0');
	else
		return (0);
	return (1);
}

void	do_printing(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (do_special_char(str[i + 1]) == 1)
				i++;
			else
				ft_putchar(str[i]);
		}
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
