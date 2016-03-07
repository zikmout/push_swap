/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:30:46 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 13:00:18 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push.h"

t_node	*ft_new_elem(int nbr, int pos, int *flags)
{
	t_node	*new_node;

	new_node = NULL;
	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		ft_putendl_fd("Error", 2);
	new_node->nbr = nbr;
	new_node->pos = pos;
	new_node->flags = flags;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*list_find_end(t_node *list)
{
	if (list->next == NULL)
		return (list);
	return (list_find_end(list->next));
}

void	delete_last(t_node **head)
{
	t_node *current;

	if ((*head)->next)
	{
		current = list_find_end(*head);
		current->prev->next = NULL;
		free(current);
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}

void	delete_first(t_node **head)
{
	t_node *current;

	if ((*head)->next)
	{
		current = *head;
		current->next->prev = NULL;
		*head = current->next;
		free(current);
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}

void	push_back(t_node **head, int nbr, int pos, int *flags)
{
	t_node *new;

	new = ft_new_elem(nbr, pos, flags);
	if (*head == NULL)
	{
		*head = new;
		(*head)->prev = (*head)->next;
		(*head)->next = NULL;
	}
	else
	{
		new->prev = list_find_end(*head);
		list_find_end(*head)->next = new;
		new->next = NULL;
	}
}
