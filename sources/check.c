/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:42:08 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 09:54:19 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push.h"

void	print_bonus(t_node *head_a, t_node *head_b, int i, int *n)
{
	if (head_a->flags[2])
		print(&head_a, &head_b);
	if (test_sort(&head_a) == 1)
		exit(0);
	i = push_swap(&head_a, &head_b);
	ft_putchar('\n');
	if (head_a->flags[2])
		print(&head_a, &head_b);
	if (head_a->flags[1])
	{
		ft_putstr("Nombre de coups : ");
		ft_putnbr(i);
		ft_putchar('\n');
	}
	free(n);
	free_lists(&head_a);
}

void	end_it(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int		check_int(t_node **head_a, int n)
{
	int		u;
	t_node	*current;

	current = *head_a;
	u = 0;
	while (current)
	{
		if (n == current->nbr)
			u = u + 1;
		current = current->next;
	}
	return (u);
}

int		check_arg(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0 && arg[i] != '-')
			return (0);
		else
			i++;
	}
	return (1);
}

int		check_double(t_node **head_a)
{
	t_node *current;

	current = *head_a;
	while (current)
	{
		if (check_int(head_a, current->nbr) >= 2)
			return (1);
		current = current->next;
	}
	return (0);
}
