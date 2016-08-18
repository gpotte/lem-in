/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:21:17 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/18 17:16:44 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init(t_env *env)
{
	env->nb_ant = 0;
	env->start = NULL;
	env->end = NULL;
}

int		main(void)
{
	t_env	env;
	t_room	*room;
	
	room = NULL;
	init(&env);
	nb_ants(&env);
	room = parse_map(&env, room);
	map_is_valid(&env);
	return(0);
}
