/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwtchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:18:07 by ssicard           #+#    #+#             */
/*   Updated: 2016/02/02 09:57:07 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getwchar2(char *str, wchar_t chr)
{
	str[0] = (chr >> 18) + 0xF0;
	str[1] = ((chr >> 12) & 0x3F) + 0x80;
	str[2] = ((chr >> 6) & 0x3F) + 0x80;
	str[3] = (chr & 0x3F) + 0x80;
	str[4] = '\0';
	return (str);
}

char		*ft_getwchar(wchar_t chr)
{
	char	*str;

	if (!(str = malloc(sizeof(char *) * 5)))
		return (NULL);
	if (chr <= 0x7F)
	{
		str[0] = chr;
		str[1] = '\0';
	}
	else if (chr <= 0x7FF)
	{
		str[0] = (chr >> 6) + 0xC0;
		str[1] = (chr & 0x3F) + 0x80;
		str[2] = '\0';
	}
	else if (chr <= 0xFFFF)
	{
		str[0] = (chr >> 12) + 0xE0;
		str[1] = ((chr >> 6) & 0x3F) + 0x80;
		str[2] = (chr & 0x3F) + 0x80;
		str[3] = '\0';
	}
	else if (chr <= 0x10FFFF)
		str = ft_getwchar2(str, chr);
	return (str);
}
