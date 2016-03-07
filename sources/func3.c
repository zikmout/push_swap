/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:19:29 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/05 08:39:39 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push.h"

void	pb(t_node **head_a, t_node **head_b, int *nb)
{
	t_node *current;

	(*nb)++;
	if ((*(head_a))->flags[4])
		print(head_a, head_b);
	if ((*(head_a))->flags[3] && *nb == 1)
		ft_putstr("\033[36mpb\033[0m");
	else if ((*(head_a))->flags[3])
		ft_putstr("\033[36m pb\033[0m");
	else if (*nb == 1)
		ft_putstr("pb");
	else
		ft_putstr(" pb");
	current = *head_a;
	push_front(head_b, current->nbr, current->pos, current->flags);
	delete_first(head_a);
}

void	pa(t_node **head_a, t_node **head_b, int *nb)
{
	t_node *current;

	(*nb)++;
	if ((*(head_a))->flags[4])
		print(head_a, head_b);
	if ((*(head_a))->flags[3] && *nb == 1)
		ft_putstr("\033[31mpa\033[0m");
	else if ((*(head_a))->flags[3])
		ft_putstr("\033[31m pa\033[0m");
	else if (*nb == 1)
		ft_putstr("pa");
	else
		ft_putstr(" pa");
	current = *head_b;
	push_front(head_a, current->nbr, current->pos, current->flags);
	delete_first(head_b);
}

void	sa(t_node **head_a, t_node **head_b, int *nb)
{
	t_node		*current;
	int			tmp;
	int			tmp2;
	int			*tmp3;

	(*nb)++;
	if ((*(head_a))->flags[3] && *nb == 1)
		ft_putstr("\033[33msa\033[0m");
	else if ((*(head_a))->flags[3])
		ft_putstr("\033[33m sa\033[0m");
	else if (*nb == 1)
		ft_putstr("sa");
	else
		ft_putstr(" sa");
	current = *head_a;
	tmp = current->nbr;
	tmp2 = current->pos;
	tmp3 = current->flags;
	current->nbr = current->next->nbr;
	current->pos = current->next->pos;
	current->flags = current->next->flags;
	current->next->nbr = tmp;
	current->next->pos = tmp2;
	current->next->flags = tmp3;
}

void	sb(t_node **head_b, t_node **head_a, int *nb)
{
	t_node		*current;
	int			tmp;
	int			tmp2;
	int			*tmp3;

	(*nb)++;
	if ((*(head_b))->flags[3] && *nb == 1)
		ft_putstr("\033[35msb\033[0m");
	else if ((*(head_b))->flags[3])
		ft_putstr("\033[35m sb\033[0m");
	else if (*nb == 1)
		ft_putstr("sb");
	else
		ft_putstr(" sb");
	current = *head_b;
	tmp = current->nbr;
	tmp2 = current->pos;
	tmp3 = current->flags;
	current->nbr = current->next->nbr;
	current->pos = current->next->pos;
	current->flags = current->next->flags;
	current->next->nbr = tmp;
	current->next->pos = tmp2;
	current->next->flags = tmp3;
}

void	ra(t_node **head_a, t_node **head_b, int *nb)
{
	t_node *current;

	(*nb)++;
	if ((*(head_a))->flags[3] && *nb == 1)
		ft_putstr("\033[34mra\033[0m");
	else if ((*(head_a))->flags[3])
		ft_putstr("\033[34m ra\033[0m");
	else if (*nb == 1)
		ft_putstr("ra");
	else
		ft_putstr(" ra");
	current = *head_a;
	push_back(head_a, current->nbr, current->pos, current->flags);
	delete_first(head_a);
}
