/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:21:17 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/23 11:46:02 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init(t_env *env)
{
	env->nb_ant = 0;
	env->start = NULL;
	env->end = NULL;
	env->weight = 0;
}

void	print_map(t_room *room)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putchar('(');
		ft_putnbr(tmp->poid);
		ft_putchar(')');
		while (tmp->link)
		{
			ft_putstr("---");
			ft_putstr(tmp->link->room->name);
			ft_putchar('(');
			ft_putnbr(tmp->link->room->poid);
			ft_putchar(')');
			tmp->link = tmp->link->next;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

int			main(void)
{
	char	**path;
	int		i;
	t_env	env;
	t_room	*room;

	i = 0;
	room = NULL;
	path = NULL;
	init(&env);
	nb_ants(&env);
	room = parse_map(&env, room);
	room = parse_pipe(&env, room);
	map_is_valid(&env);
	room = set_weights(&env, room);
	path = finding_path(&env, room, path);
	print_map(room);
	while (path[i])
		ft_putendl(path[i++]);
	return (0);
}
