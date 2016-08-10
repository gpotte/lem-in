/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:07:11 by gpotte            #+#    #+#             */
/*   Updated: 2015/11/27 17:57:59 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = 0;
	k = ft_strlen(s2);
	l = ft_strlen(s1);
	if (k == 0)
		return ((char *)s1);
	while (i < n && i < l)
	{
		while (s1[i] == s2[j] && i < n)
		{
			if (j == k - 1)
				return ((char *)s1 + i - j);
			i++;
			j++;
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
