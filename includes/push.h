/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 08:02:25 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 09:57:52 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

typedef	struct s_node	t_node;

struct				s_node
{
	int				nbr;
	int				pos;
	int				*flags;
	struct s_node	*next;
	struct s_node	*prev;
};

void				print_list(t_node **list);
void				print(t_node **head_a, t_node **head_b);
t_node				*ft_new_elem(int nbr, int pos, int *flags);
t_node				*list_find_end(t_node *list);
void				push_back(t_node **head, int nbr, int pos, int *flags);
void				push_front(t_node **head, int nbr, int pos, int *flags);
void				delete_last(t_node **head);
void				delete_first(t_node **head);
int					get_size(t_node **head);
t_node				*list_at(t_node **head, int pos);
void				fill_pos(t_node **head_a);
void				print_bonus(t_node *head_a, t_node *head_b, int i, int *n);
int					push_swap(t_node **head_a, t_node **head_b);
int					push_swap13(t_node **head_a, t_node **head_b, int nb);
int					selection_sort(t_node **head_a, t_node **head_b, int nb,\
		int n);
int					push_swap320(t_node **head_a, t_node **head_b, int nb,\
		int n);
int					push_swap2(t_node **head_a, t_node **head_b);
int					push_swapsa(t_node **head_a, t_node **head_b);
void				pa(t_node **head_a, t_node **head_b, int *nb);
void				pb(t_node **head_a, t_node **head_b, int *nb);
void				sa(t_node **head_a, t_node **head_b, int *nb);
void				sb(t_node **head_b, t_node **head_a, int *nb);
void				ra(t_node **head_a, t_node **head_b, int *nb);
void				rb(t_node **head_b, t_node **head_a, int *nb);
void				rra(t_node **head_a, t_node **head_b, int *nb);
void				rrb(t_node **head_b, t_node **head_a, int *nb);
int					ssplit(t_node **head_a, t_node **head_b, int size, int *nb);
int					algo(t_node **head_a, t_node **head_b);
int					get_mid(t_node **head, int n, int inf, int sup);
int					*find_max(t_node **head);
int					*find_min(t_node **head_a, t_node **head_b);
void				try(t_node **head_a, t_node **head_b, int *nb);
int					try2(t_node **head_a, t_node **head_b, int nb_to_sort,\
		int *nb);
void				sort_it(t_node **head_a, t_node **head_b, int *nb);
int					test_sort(t_node **head_a);
int					nb_non_sort(t_node **head_a);
int					nb_non_sort2(t_node **head_a);
int					enter_swapsa(t_node **head_a, t_node **head_b);
int					check_double(t_node **head_a);
int					check_arg(char *arg);
int					check_int(t_node **head_a, int n);
void				end_it(void);
int					ft_atoi_spec(const char *str);
int					*get_options(char **av);
void				free_lists(t_node **head_a);
#endif
