/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:41:38 by gpotte            #+#    #+#             */
/*   Updated: 2016/06/10 10:35:13 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

int		ft_putwchar(wchar_t c)
{
	if (c < 0x80)
		ft_putchar(c);
	else if (c < 0x800)
	{
		ft_putchar(0xC0 | c >> 6);
		ft_putchar(0x80 | (c & 0x3F));
		return (2);
	}
	else if (c < 0x10000)
	{
		ft_putchar(0xE0 | c >> 12);
		ft_putchar(0x80 | (c >> 6 & 0x3F));
		ft_putchar(0x80 | (c & 0x3F));
		return (3);
	}
	else if (c < 0x200000)
	{
		ft_putchar(0xF0 | c >> 18);
		ft_putchar(0x80 | (c >> 12 & 0x3F));
		ft_putchar(0x80 | (c >> 6 & 0x3F));
		ft_putchar(0x80 | (c & 0x3F));
		return (4);
	}
	return (1);
}
