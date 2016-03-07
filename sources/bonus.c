/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:38:49 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 09:54:20 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push.h"

static	int	*tab_zero(int *ret)
{
	ret[0] = 0;
	ret[1] = 0;
	ret[2] = 0;
	ret[3] = 0;
	ret[4] = 0;
	return (ret);
}

static	int	valid_opt(char **av)
{
	char a;
	char b;
	char c;
	char d;

	if ((av[1][0] == '`') == 0)
		return (1);
	if (av[1] && av[1][1])
		a = av[1][1];
	if (av[2] && av[2][1])
		b = av[2][1];
	if (av[3] && av[3][1])
		c = av[3][1];
	if (av[4] && av[4][1])
		d = av[4][1];
	if ((av[1] && av[1][1]) && (a == 'd' || a == 'p' || a == 'c' || a == 'n'))
		return (1);
	if ((av[2] && av[2][1]) && (b == 'd' || b == 'p' || b == 'c' || b == 'n'))
		return (1);
	if ((av[3] && av[3][1]) && (c == 'd' || c == 'p' || c == 'c' || c == 'n'))
		return (1);
	if ((av[4] && av[4][1]) && (d == 'd' || d == 'p' || d == 'c' || d == 'n'))
		return (1);
	return (0);
}

static	int	valid_opt2(char **av, int *ret)
{
	if (ret[0] == 1 && !av[2])
		return (0);
	else if (ret[0] == 2 && !av[3])
		return (0);
	else if (ret[0] == 3 && !av[4])
		return (0);
	else if (ret[0] == 4 && !av[5])
		return (0);
	return (1);
}

static	int	cmp_arg(char **av, char *str)
{
	if ((av[1] && ft_strcmp(av[1], str) == 0)
			|| (av[2] && ft_strcmp(av[2], str) == 0)
			|| (av[3] && ft_strcmp(av[3], str) == 0)
			|| (av[4] && ft_strcmp(av[4], str) == 0))
		return (1);
	return (0);
}

int			*get_options(char **av)
{
	int		*ret;
	int		i;

	i = 0;
	if (!(ret = (int *)malloc(sizeof(int) * 5)))
		return (0);
	ret = tab_zero(ret);
	if ((av[1] && av[1][0] == '-') || (av[2] && av[2][0] == '-')
			|| (av[3] && av[3][0] == '-') || (av[4] && av[4][0] == '-'))
	{
		if (valid_opt(av) == 0)
			end_it();
		if (cmp_arg(av, "-n"))
			ret[1] = 1;
		if (cmp_arg(av, "-p"))
			ret[2] = 1;
		if (cmp_arg(av, "-c"))
			ret[3] = 1;
		if (cmp_arg(av, "-d"))
			ret[4] = 1;
	}
	ret[0] = ret[1] + ret[2] + ret[3] + ret[4];
	if (valid_opt2(av, ret) == 0)
		end_it();
	return (ret);
}
