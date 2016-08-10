/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:14:08 by gpotte            #+#    #+#             */
/*   Updated: 2016/05/17 18:20:34 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s2 = ft_strnew(7);
		s2 = ft_strcpy(s2, "(null)");
		return (s2);
	}
	j = ft_strlen(s1);
	s2 = ft_strnew(j + 1);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

wchar_t	*ft_strdup_wchar(const wchar_t *s1)
{
	wchar_t	*s2;
	size_t	i;
	size_t	j;

	j = ft_strlen((char *)s1);
	if ((s2 = ft_memalloc(j + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
