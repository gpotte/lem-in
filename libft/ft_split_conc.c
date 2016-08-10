/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_conc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 13:38:20 by gpotte            #+#    #+#             */
/*   Updated: 2016/06/10 11:44:45 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_split_conc(char *str, char c)
{
	char	**tmp;
	int		i;

	i = 1;
	tmp = ft_strsplit(str, c);
	free(str);
	str = ft_strdup(tmp[0]);
	while (tmp[i])
	{
		str = ft_strjoin_free1(str, tmp[i]);
		i++;
	}
	free(tmp);
	return (str);
}
