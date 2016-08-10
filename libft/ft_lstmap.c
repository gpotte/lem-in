/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:58:23 by gpotte            #+#    #+#             */
/*   Updated: 2015/12/19 14:48:56 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*new2;

	new = lst;
	new2 = new;
	while (new->next)
	{
		f(lst);
		new = malloc(sizeof(lst));
		new = lst;
		new2 = malloc(sizeof(lst));
		new2 = new;
		lst = lst->next;
		new = new->next;
	}
	f(lst);
	new = malloc(sizeof(lst));
	new = lst;
	return (new2);
}
