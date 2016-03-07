/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 10:17:08 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 10:00:14 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push.h"

int		main(int ac, char **av)
{
	t_node	*head_a;
	t_node	*head_b;
	int		*tab;
	int		*n;
	int		d;

	head_a = NULL;
	head_b = NULL;
	if (ac < 2)
		exit(0);
	n = get_options(av);
	d = n[0];
	n[0] = get_size(&head_a);
	while (ac - 1 > d)
	{
		if (check_arg(av[ac - 1]) == 0)
			end_it();
		push_front(&head_a, ft_atoi_spec(av[ac-- - 1]), 0, n);
	}
	if (check_double(&head_a) == 1)
		end_it();
	print_bonus(head_a, head_b, ac, n);
	return (0);
}
