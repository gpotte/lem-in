/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 14:07:08 by gpotte            #+#    #+#             */
/*   Updated: 2016/08/18 17:44:52 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
** INCLUDE LIB
*/

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

/*
** DEFINE COLOR
*/

# define ANSI_RED     "\x1b[31m"
# define ANSI_GREEN   "\x1b[32m"
# define ANSI_YELLOW  "\x1b[33m"
# define ANSI_BLUE    "\x1b[34m"
# define ANSI_MAGENTA "\x1b[35m"
# define ANSI_CYAN    "\x1b[36m"
# define ANSI_RESET   "\x1b[0m"

/*
** STRUCTURE DEFINITION
*/

typedef	struct			s_linkroom
{
	struct s_room		*room;
	struct s_linkroom	*next;
}						t_linkroom;

typedef struct			s_room
{
	int					poids;
	char				*name;
	struct s_room		*next;
	struct s_linkroom	*link;
}						t_room;

typedef	struct			s_env
{
	char				*line;
	int					nb_ant;
	char				*start;
	char				*end;
}						t_env;

/*
** FUNCTIONS
*/

t_room					*parse_map(t_env *env, t_room *room);
void					nb_ants(t_env *env);

void					ft_error();

t_room					*add_room(t_room *room, char *name, int i);

void					map_is_valid(t_env *env);
#endif
