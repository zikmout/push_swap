/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 11:29:44 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/04 11:30:30 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push.h"

void		free_lists(t_node **head_a)
{
	t_node	*current_a;
	t_node	*tmp;

	current_a = *head_a;
	tmp = NULL;
	while (current_a)
	{
		tmp = current_a;
		current_a = current_a->next;
		free(tmp);
	}
}

int			algo(t_node **head_a, t_node **head_b)
{
	int		size_sorted_a;
	int		size_tmp;
	int		nb_moves;

	nb_moves = 0;
	size_sorted_a = 0;
	while (*head_b || test_sort(head_a) == 0)
	{
		size_tmp = get_size(head_a) - size_sorted_a;
		while (size_tmp > 2)
			size_tmp = ssplit(head_a, head_b, size_sorted_a, &nb_moves);
		if (size_tmp == 2 && (*head_a)->nbr > (*head_a)->next->nbr)
			sa(head_a, head_b, &nb_moves);
		size_sorted_a = size_sorted_a + size_tmp;
		size_sorted_a = size_sorted_a + try2(head_a, head_b, 200, &nb_moves);
		while (*head_b)
			pa(head_a, head_b, &nb_moves);
	}
	return (nb_moves);
}
