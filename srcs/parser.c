/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:53:18 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/18 17:40:31 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*parse_map(t_env *env, t_room *room)
{
	int	i;
	int	status;

	status = 0;
	while (get_next_line(0, &env->line) > 0)
	{
		if (!ft_strchr(env->line, ' ') && env->line[0] != '#')
			break ;
		if (!ft_strcmp(env->line, "##start"))
			status = 1;
		if (!ft_strcmp(env->line, "##end"))
			status = 2;
		if (env->line[0] != '#')
		{
			i = ft_strchr(env->line, ' ') - env->line;
			room = add_room(room, env->line, i);
			if (status == 1)
				env->start = ft_strndup(env->line, i);
			if (status == 2)
				env->end = ft_strndup(env->line, i);
			status = 0;
		}
		free(env->line);
	}
	return (room);
}

void	nb_ants(t_env *env)
{
	if (get_next_line(0, &env->line) < 1)
		ft_error();
	if ((env->nb_ant = ft_atoi(env->line)) < 1)
		ft_error();
	free(env->line);
}
