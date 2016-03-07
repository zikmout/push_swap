/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:00:33 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/05 07:56:46 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push.h"

static	void	get_no(int *tab, int *nb, t_node **head_a, t_node **head_b)
{
	int			tmp;

	tmp = tab[1];
	if (tab[1] > 0)
		while (tmp--)
			rb(head_b, head_a, nb);
	else
		while (tmp++)
			rrb(head_b, head_a, nb);
	pa(head_a, head_b, nb);
}

static	void	get_no2(int *nb, t_node **head_a, t_node **head_b)
{
	sb(head_b, head_a, nb);
	pa(head_a, head_b, nb);
}

int				try2(t_node **head_a, t_node **head_b, int nb_to_sort, int *nb)
{
	int			*tab;
	int			size;
	int			res;

	res = 0;
	while (*head_b)
	{
		size = get_size(head_b);
		if (res == nb_to_sort)
			break ;
		tab = find_max(head_b);
		if (tab[1] == 0)
			pa(head_a, head_b, nb);
		else if (tab[1] == 1)
			get_no2(tab, head_a, head_b);
		else
		{
			if (tab[1] > size / 2)
				tab[1] = tab[1] - size;
			get_no(tab, nb, head_a, head_b);
		}
		res++;
		free(tab);
	}
	return (res);
}

int				push_swap2(t_node **head_a, t_node **head_b)
{
	int			nb;

	nb = 0;
	if ((*head_a)->nbr > (*head_a)->next->nbr)
		sa(head_a, head_b, &nb);
	else
		exit(0);
	return (nb);
}
