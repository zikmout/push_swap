/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cslen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 09:27:40 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/05 08:12:49 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_cslen(wchar_t wc)
{
	size_t	len2;

	len2 = 0;
	if (wc < 0x80)
		len2 = 1;
	else if (wc < 0x0800)
		len2 = 2;
	else if (wc < 0x10000)
		len2 = 3;
	else if (wc < 0x110000)
		len2 = 4;
	return (len2);
}
