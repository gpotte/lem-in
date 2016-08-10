/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:58:05 by gpotte            #+#    #+#             */
/*   Updated: 2015/12/19 14:49:30 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*alst || !alst)
		return ;
	tmp = *alst;
	tmp2 = *alst;
	while (tmp->next)
	{
		tmp = tmp->next;
		del(tmp2->content, tmp2->content_size);
		free(tmp2);
		tmp2 = tmp;
	}
	del(tmp2->content, tmp2->content_size);
	free(tmp2);
	*alst = NULL;
}
