/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:07:09 by gpotte            #+#    #+#             */
/*   Updated: 2016/02/25 13:36:07 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	nbr_char(char const *s, char c, int n, int i)
{
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

static size_t	len_alloc(char const *s, char c, size_t start, size_t i)
{
	size_t	len;

	while (s[i] != c && s[i] != '\0')
		i++;
	len = i - start;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	n;
	size_t	len;
	size_t	word;
	char	**str;

	n = 0;
	i = 0;
	word = nbr_char(s, c, 0, 0);
	if ((str = (char **)malloc(sizeof(char *) * (word + 1))) == NULL)
		return (NULL);
	str[word] = NULL;
	while (n < word)
	{
		while (s[i] == c)
			i++;
		len = len_alloc(s, c, i, i);
		if (!(str[n] = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strncpy(str[n], s + i, len);
		str[n][len] = '\0';
		n++;
		i += len;
	}
	return (str);
}
