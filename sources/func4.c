/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:20:49 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 11:06:27 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push.h"

int				ssplit(t_node **head_a, t_node **head_b, int size, int *nb)
{
	int			med;
	int			n;
	int			nb_ra;
	int			sup;
	int			inf;

	n = get_size(head_a) - size;
	med = get_mid(head_a, n, inf, sup);
	nb_ra = 0;
	while (n--)
	{
		if ((*head_a)->nbr < med)
			pb(head_a, head_b, nb);
		else
		{
			ra(head_a, head_b, nb);
			if (size != 0)
				nb_ra++;
		}
	}
	while (nb_ra--)
		rra(head_a, head_b, nb);
	return (get_size(head_a) - size);
}

static int		get_no(t_node *v, int n, int sup, int inf)
{
	if (inf == (n / 2))
		return (v->nbr);
	if (sup == (n - 1 - n / 2))
		return (v->nbr);
	return (0);
}

int				get_mid(t_node **head, int n, int inf, int sup)
{
	int			size1;
	int			size2;
	t_node		*v;
	t_node		*current;

	size1 = n;
	v = *head;
	while (v && size1--)
	{
		sup = 0;
		inf = 0;
		current = *head;
		size2 = n;
		while (current && size2--)
		{
			inf = (current->nbr < v->nbr) ? (inf + 1) : (inf);
			sup = (current->nbr > v->nbr) ? (sup + 1) : (sup);
			current = current->next;
		}
		if (inf == (n / 2) || sup == (n - 1 - n / 2))
			return (get_no(v, n, sup, inf));
		v = v->next;
	}
	return (0);
}

int				*find_max(t_node **head)
{
	int			*tmp;
	int			pos;
	t_node		*current;

	current = *head;
	if (!(tmp = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	tmp[0] = current->nbr;
	tmp[1] = 0;
	pos = 0;
	while (current)
	{
		if (current->nbr > tmp[0])
		{
			tmp[1] = pos;
			tmp[0] = current->nbr;
		}
		pos++;
		current = current->next;
	}
	return (tmp);
}
