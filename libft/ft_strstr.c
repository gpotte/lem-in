/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:45:29 by gpotte            #+#    #+#             */
/*   Updated: 2015/11/27 17:33:44 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	l = 0;
	if (j == 0)
		return ((char *)s1);
	while (k != i)
	{
		while (s1[k] == s2[l])
		{
			k++;
			l++;
			if (l == j)
				return ((char *)s1 + k - j);
		}
		k = k - l + 1;
		l = 0;
	}
	return (NULL);
}
