/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:34:59 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/22 15:59:08 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char **finding_path(t_env *env, t_room *room)
{
	char		**path;
	int			i;
	t_room		*tmp;
	t_linkroom	*tmp_link;
	t_linkroom	*link_index;

	tmp = room;
	i = 0;
	path = (char **)malloc(sizeof(char *) * env->weight);
	while (ft_strcmp(tmp->name, env->start))
		tmp = tmp->next;
	while (ft_strcmp(tmp->name, env->end))
	{
		path[i] = ft_strdup(tmp->name);
		tmp_link = tmp->link;
		link_index = tmp->link;
		while (link_index)
		{
			if (link_index->room->poid < tmp_link->room->poid)
				while (tmp_link->room->poid > link_index->room->poid)
					tmp_link = tmp_link->next;
			link_index = link_index->next;
		}
		tmp = tmp_link->room;
		i++;
	}
	path[i] = ft_strdup(tmp->name);
	path[i + 1] = NULL;
	i = 0;
	while (path[i])
	{
		ft_putstr("Debug: ");
		ft_putendl(path[i++]);
	}
	return (path);
}
