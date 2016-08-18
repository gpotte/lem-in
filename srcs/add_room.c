/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:32:36 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/18 16:38:27 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	add_room(t_room *room, char *name)
{
	t_room *new_room;

	new_room = malloc(sizeof(t_room));
	new_room->name = ft_strdup(name);
	new_room->next = NULL;

	if (room == NULL)
		return (new_room);
	else
	{
		t_room	*tmp;
		tmp = room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_room;
		return (room);
	}
}
