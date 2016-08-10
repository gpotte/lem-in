/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:29:52 by gpotte            #+#    #+#             */
/*   Updated: 2016/02/16 13:18:14 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	if ((s = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
