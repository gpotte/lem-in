/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:01:51 by gpotte            #+#    #+#             */
/*   Updated: 2016/05/28 15:30:41 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_size(long long int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa_ll(long long int n, int base)
{
	size_t	len;
	char	*str;

	len = get_size(n);
	str = ft_strnew(len + 1);
	if (n == 0)
		ft_strcpy(str, "0");
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		if ((n % base) < 10)
			str[len - 1] = n % base + 48;
		else
			str[len - 1] = n % base + 87;
		n = n / base;
		--len;
	}
	return (str);
}
