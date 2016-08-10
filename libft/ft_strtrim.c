/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:38:46 by gpotte            #+#    #+#             */
/*   Updated: 2015/11/30 17:05:34 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	k;
	char	*dst;

	i = 0;
	k = ft_strlen(s);
	while (s[k - 1] == ' ' || s[k - 1] == '\n' || s[k - 1] == '\t')
		k--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s))
	{
		dst = "";
		return (dst);
	}
	len = k - i;
	if ((dst = ft_strsub(s, i, len)) == NULL)
		return (NULL);
	dst[len] = '\0';
	return (dst);
}
