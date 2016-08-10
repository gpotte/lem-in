/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:02:42 by gpotte            #+#    #+#             */
/*   Updated: 2016/05/16 15:52:03 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	get_size(int n)
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

static char		*str_min(char **str)
{
	ft_strcpy(*str, "-2147483648");
	return (*str);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = get_size(n);
	str = ft_strnew(len + 1);
	if (n == 0)
		ft_strcpy(str, "0");
	if (n == -2147483648)
		return (str_min(&str));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		--len;
	}
	return (str);
}

char			*ft_itoa_unsigned(unsigned int n)
{
	size_t			len;
	unsigned int	tmp;
	char			*str;

	len = 0;
	tmp = n;
	if (tmp == 0)
		len++;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	str = ft_strnew(len + 1);
	if (n == 0)
		ft_strcpy(str, "0");
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		--len;
	}
	return (str);
}
