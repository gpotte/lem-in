/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:53:18 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/19 11:43:05 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*first_turn(t_env *env, t_room *room)
{
	char **pipe;

	if (!ft_strchr(env->line, '-') && env->line[0] != '#')
		ft_error();
	if (env->line[0] != '#')
	{
		pipe = ft_strsplit(env->line, '-');
		room = add_link(room, pipe[0], pipe[1]);
		free(pipe[0]);
		free(pipe[1]);
		free(pipe);
	}
	free(env->line);
	return (room);
}

void			nb_ants(t_env *env)
{
	if (get_next_line(0, &env->line) < 1)
		ft_error();
	if ((env->nb_ant = ft_atoi(env->line)) < 1)
		ft_error();
	free(env->line);
}

t_room			*parse_map(t_env *env, t_room *room)
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

t_room			*parse_pipe(t_env *env, t_room *room)
{
	char **pipe;

	if (env->line)
		room = first_turn(env, room);
	while (get_next_line(0, &env->line) > 0)
	{
		if (!ft_strchr(env->line, '-') && env->line[0] != '#')
			break ;
		if (env->line[0] != '#')
		{
			pipe = ft_strsplit(env->line, '-');
			room = add_link(room, pipe[0], pipe[1]);
			free(pipe[0]);
			free(pipe[1]);
			free(pipe);
		}
		free(env->line);
	}
	return (room);
}
