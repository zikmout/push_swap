/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:43:32 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 12:55:41 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push.h"

void	push_front(t_node **head, int nbr, int pos, int *flags)
{
	t_node *new;

	new = ft_new_elem(nbr, pos, flags);
	if (*head)
	{
		new->nbr = nbr;
		new->pos = pos;
		new->flags = flags;
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
	else
	{
		new->flags = flags;
		*head = new;
		(*head)->prev = (*head)->next;
		(*head)->next = NULL;
	}
}

void	rb(t_node **head_b, t_node **head_a, int *nb)
{
	t_node *current;

	(*nb)++;
	if ((*(head_b))->flags[3] && *nb == 1)
		ft_putstr("\033[32mrb\033[0m");
	else if ((*(head_b))->flags[3])
		ft_putstr("\033[32m rb\033[0m");
	else if (*nb == 1)
		ft_putstr("rb");
	else
		ft_putstr(" rb");
	current = *head_b;
	push_back(head_b, current->nbr, current->pos, current->flags);
	delete_first(head_b);
}

void	rra(t_node **head_a, t_node **head_b, int *nb)
{
	t_node *current;

	(*nb)++;
	if ((*(head_a))->flags[3] && *nb == 1)
		ft_putstr("\033[1;34mrra\033[0m");
	else if ((*(head_a))->flags[3])
		ft_putstr("\033[1;34m rra\033[0m");
	else if (*nb == 1)
		ft_putstr("rra");
	else
		ft_putstr(" rra");
	current = list_find_end(*head_a);
	push_front(head_a, current->nbr, current->pos, current->flags);
	delete_last(head_a);
}

void	rrb(t_node **head_b, t_node **head_a, int *nb)
{
	t_node *current;

	(*nb)++;
	if ((*(head_b))->flags[3] && *nb == 1)
		ft_putstr("\033[1;33mrrb\033[0m");
	else if ((*(head_b))->flags[3])
		ft_putstr("\033[1;33m rrb\033[0m");
	else if (*nb == 1)
		ft_putstr("rrb");
	else
		ft_putstr(" rrb");
	current = list_find_end(*head_b);
	push_front(head_b, current->nbr, current->pos, current->flags);
	delete_last(head_b);
}

int		*find_min(t_node **head_a, t_node **head_b)
{
	int		*tmp;
	t_node	*current;
	t_node	*current2;
	int		pos;

	pos = 0;
	if (!(tmp = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	current = *head_a;
	current2 = *head_b;
	tmp[0] = 2147483647;
	while (current)
	{
		if (((current->nbr < tmp[0]) && current2 == 0) ||
				((current->nbr < tmp[0]) && ((current->nbr > current2->nbr)
					&& current2->pos == 0)))
		{
			tmp[1] = pos;
			tmp[0] = current->nbr;
		}
		current = current->next;
		pos++;
	}
	return (tmp);
}
