/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:11:38 by gpotte            #+#    #+#             */
/*   Updated: 2016/06/07 13:35:36 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*it_ret(char *str, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(len + 1);
	while (str[i])
	{
		tmp[i] = str[ft_strlen(str) - i - 1];
		i++;
	}
	free(str);
	return (tmp);
}

static size_t	get_size(long long int n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(long long int n, int base)
{
	size_t	len;
	char	*str;

	len = get_size(n, base);
	str = ft_strnew(len + 1);
	if (n == 0)
		ft_strcpy(str, "0");
	len = 0;
	while (n != 0)
	{
		if ((n % base) < 10)
			str[len] = n % base + 48;
		else
			str[len] = n % base + 87;
		n = n / base;
		++len;
	}
	return (it_ret(str, len));
}

static size_t	get_usize(unsigned long long int n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char			*ft_uitoa_base(unsigned long long int n, int base)
{
	size_t	len;
	char	*str;

	len = get_usize(n, base);
	str = ft_strnew(len + 1);
	if (n == 0)
		ft_strcpy(str, "0");
	len = 0;
	while (n != 0)
	{
		if ((n % base) < 10)
			str[len] = n % base + 48;
		else
			str[len] = n % base + 87;
		n = n / base;
		++len;
	}
	return (it_ret(str, len));
}
