/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:32:36 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/18 17:38:57 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*add_room(t_room *room, char *name, int i)
{
	t_room	*new_room;
	t_room	*tmp;

	new_room = malloc(sizeof(t_room));
	new_room->name = ft_strndup(name, i);
	new_room->next = NULL;
	if (room == NULL)
		return (new_room);
	else
	{
		tmp = room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_room;
		return (room);
	}
}
