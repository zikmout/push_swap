/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:18:01 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/03 21:06:52 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"
#include <limits.h>

int	ft_atoi_spec(const char *str)
{
	int			is_negative;
	long long	nb;

	is_negative = 0;
	nb = 0;
	while ((*str == ' ') || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '-')
		is_negative = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nb = (nb * 10) + (*str - '0');
		if (nb > (long long)INT_MAX + 1
				|| (nb == (long long)INT_MAX + 1 && !is_negative))
			end_it();
		str++;
	}
	if (is_negative == 1)
		return (-(int)nb);
	else
		return ((int)nb);
}
