/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:07:14 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/04 11:59:58 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push.h"

void		print_list(t_node **head)
{
	t_node	*current;

	if (*head)
	{
		current = list_find_end(*head);
		while (current != NULL)
		{
			ft_putnbr(current->nbr);
			ft_putchar(' ');
			current = current->prev;
		}
	}
}

void		print(t_node **head_a, t_node **head_b)
{
	ft_putstr("\nListe A : ");
	print_list(head_a);
	ft_putchar('\n');
	ft_putstr("Liste B : ");
	print_list(head_b);
	ft_putchar('\n');
}

int			get_size(t_node **head)
{
	int		size;
	t_node	*current;

	size = 0;
	current = *head;
	while (current)
	{
		size = size + 1;
		current = current->next;
	}
	return (size);
}

t_node		*list_at(t_node **head, int pos)
{
	t_node	*current;

	current = *head;
	while (pos--)
		current = current->next;
	return (current);
}

void		fill_pos(t_node **head_a)
{
	int		pos;
	int		pos2;
	int		size;

	size = get_size(head_a);
	pos = 0;
	while (pos < size)
	{
		pos2 = 0;
		while (pos2 < size)
		{
			if ((list_at(head_a, pos))->nbr < (list_at(head_a, pos2))->nbr)
				list_at(head_a, pos)->pos++;
			pos2++;
		}
		pos++;
	}
}
