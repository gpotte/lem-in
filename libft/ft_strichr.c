/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:45:03 by gpotte            #+#    #+#             */
/*   Updated: 2015/12/19 18:09:27 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strichr(char *s, int c)
{
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (-1);
	i = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
