/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:10:58 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 13:11:17 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push.h"

int			push_swap(t_node **head_a, t_node **head_b)
{
	int		size;
	int		nb;
	int		n;

	if (*head_a == NULL)
		end_it();
	n = 0;
	nb = 0;
	size = get_size(head_a);
	if (size == 2)
		nb = push_swap2(head_a, head_b);
	else if (size == 3)
		nb = push_swap13(head_a, head_b, nb);
	else if (enter_swapsa(head_a, head_b) != 0 && get_size(head_a) != 5
			&& get_size(head_a) != 4)
		nb = push_swapsa(head_a, head_b);
	else if (size < 20 && size > 3)
		nb = push_swap320(head_a, head_b, nb, n);
	else if (nb_non_sort(head_a) < 10 && size > 100)
		nb = selection_sort(head_a, head_b, nb, n);
	else
		nb = algo(head_a, head_b);
	return (nb);
}

int			push_swapsa(t_node **head_a, t_node **head_b)
{
	int		nb;
	t_node	*current;

	nb = 0;
	current = *head_a;
	if (current->nbr > current->next->nbr)
		sa(head_a, head_b, &nb);
	current = list_find_end(*head_a);
	if (current->nbr < current->prev->nbr)
	{
		rra(head_a, head_b, &nb);
		rra(head_a, head_b, &nb);
		sa(head_a, head_b, &nb);
		ra(head_a, head_b, &nb);
		ra(head_a, head_b, &nb);
	}
	return (nb);
}

int			push_swap320(t_node **head_a, t_node **head_b, int nb, int n)
{
	int		*tab;
	int		size;
	t_node	*current;

	current = *head_a;
	size = get_size(head_a);
	while (get_size(head_a) != 3)
	{
		tab = find_min(head_a, head_b);
		if ((size - n) / 2 - tab[1] > 0)
			while (tab[1]--)
				ra(head_a, head_b, &nb);
		else
			while ((size - n - tab[1]++) > 0)
				rra(head_a, head_b, &nb);
		n++;
		pb(head_a, head_b, &nb);
		if (current->next)
			current = current->next;
	}
	nb = push_swap13(head_a, head_b, nb);
	while (*head_b)
		pa(head_a, head_b, &nb);
	return (nb);
}

int			selection_sort(t_node **head_a, t_node **head_b, int nb, int n)
{
	int		size;
	int		*tab;
	t_node	*current;

	current = *head_a;
	size = get_size(head_a);
	while (n != size)
	{
		tab = find_min(head_a, head_b);
		if ((size - n) / 2 - tab[1] > 0)
			while (tab[1]--)
				ra(head_a, head_b, &nb);
		else
			while ((size - n - tab[1]++) > 0)
				rra(head_a, head_b, &nb);
		n++;
		if (get_size(head_a) != 1)
			pb(head_a, head_b, &nb);
		current = (current->next) ? (current->next) : (current);
		free(tab);
	}
	size = get_size(head_b);
	while (size--)
		pa(head_a, head_b, &nb);
	return (nb);
}

int			push_swap13(t_node **head_a, t_node **head_b, int nb)
{
	fill_pos(head_a);
	if ((*head_a)->pos == 1 && (*head_a)->next->pos == 0)
	{
		ra(head_a, head_b, &nb);
		ra(head_a, head_b, &nb);
	}
	else if ((*head_a)->pos == 2 && (*head_a)->next->pos == 0)
	{
		rra(head_a, head_b, &nb);
		sa(head_a, head_b, &nb);
	}
	else if ((*head_a)->pos == 1 && (*head_a)->next->pos == 2)
		sa(head_a, head_b, &nb);
	else if ((*head_a)->pos == 0 && (*head_a)->next->pos == 2)
		ra(head_a, head_b, &nb);
	else if ((*head_a)->pos == 0 && (*head_a)->next->pos == 1)
	{
		ra(head_a, head_b, &nb);
		sa(head_a, head_b, &nb);
	}
	return (nb);
}
