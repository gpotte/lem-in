/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 11:20:03 by gpotte            #+#    #+#             */
/*   Updated: 2016/02/24 17:17:51 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>

static int	gnl(char **line, char **stock, int fd, int rd)
{
	int			i;

	i = -1;
	while (rd > 0)
	{
		i = (!(ft_strchr(*stock, '\n'))) ? -1 :
			(ft_strchr(*stock, '\n')) - *stock;
		if (i != -1)
		{
			(*stock)[i] = '\0';
			*line = ft_strjoin_free1(*line, *stock);
			*stock = ft_strcpy(*stock, *stock + i + 1);
			return (1);
		}
		*line = ft_strjoin_free1(*line, *stock);
		ft_bzero(*stock, BUFF_SIZE);
		rd = read(fd, *stock, BUFF_SIZE);
		(*stock)[rd] = '\0';
	}
	if ((*line)[0])
		return (1);
	*line = NULL;
	return (rd);
}

int			get_next_line(int fd, char **line)
{
	int			rd;
	static char	*stock[256];

	rd = BUFF_SIZE;
	if (fd < 0 || fd > 255 || line == NULL)
		return (-1);
	if (!stock[fd])
	{
		if ((stock[fd] = ft_strnew(BUFF_SIZE + 1)) == NULL)
			return (-1);
	}
	if ((*line = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	return (gnl(line, &stock[fd], fd, rd));
}
