/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:27:30 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/03 21:30:16 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push.h"

void		try(t_node **head_a, t_node **head_b, int *nb)
{
	int		*tab;
	int		tmp;
	int		size;

	size = get_size(head_b);
	tab = find_max(head_b);
	if (tab[1] == 0)
		pa(head_a, head_b, nb);
	else
	{
		if (tab[1] > size / 2)
			tab[1] = tab[1] - size;
		tmp = tab[1];
		if (tab[1] > 0)
			while ((tmp > 0) && tmp--)
				rb(head_b, head_a, nb);
		else
			while ((tmp < 0) && tmp++)
				rrb(head_b, head_a, nb);
		pa(head_a, head_b, nb);
	}
	free(tab);
}

int			test_sort(t_node **head_a)
{
	t_node	*current;

	current = *head_a;
	if (!current)
		return (0);
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}

int			nb_non_sort(t_node **head_a)
{
	t_node	*current;
	int		nb;
	int		tot;

	nb = 0;
	tot = 0;
	current = *head_a;
	if (!current)
		return (0);
	while (current->next)
	{
		tot++;
		if (current->nbr == current->next->nbr + 1)
			nb++;
		current = current->next;
	}
	return (tot - nb);
}

int			nb_non_sort2(t_node **head_a)
{
	t_node	*current;
	int		nb;
	int		tot;

	nb = 0;
	tot = 0;
	current = *head_a;
	if (!current)
		return (0);
	while (current->next)
	{
		tot++;
		if (current->nbr > current->next->nbr)
			nb++;
		current = current->next;
	}
	return (nb);
}

int			enter_swapsa(t_node **head_a, t_node **head_b)
{
	t_node	*current;
	t_node	*current2;

	current = *head_a;
	current2 = list_find_end(*head_a);
	if (nb_non_sort2(head_a) == 2)
	{
		if (current->nbr > current->next->nbr
				&& current2->prev->nbr > current2->nbr)
			return (1);
	}
	else if (nb_non_sort2(head_a) == 1)
	{
		if (current->nbr > current->next->nbr
				|| current2->prev->nbr > current2->nbr)
			return (1);
	}
	return (0);
}
