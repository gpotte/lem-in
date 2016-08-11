/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:53:18 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/11 17:11:43 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_map(t_env *env, t_room *room)
{
	int	i;

	if (get_next_line(0, &env->line) < 1)
		ft_error();
	if ((env->nb_ant = ft_atoi(env->line)) < 1)
		ft_error();
	while (get_next_line(0, &env->line) > 0)
	{
		if (!ft_strchr(env->line, ' ') && env->line[0] != '#')
			break ;
		if (!ft_strcmp(env->line, "##start"))
			env->start = room;
		if (!ft_strcmp(env->line, "##end"))
			env->end = room;
		if (env->line[0] != '#')
		{
			i = ft_strchr(env->line, ' ') - env->line;
			room->name = ft_strndup(env->line, i);
			ft_putendl(room->name);
		}
	}
}
