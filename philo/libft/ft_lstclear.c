/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:53:53 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 16:53:54 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*t;

	if (lst && del)
	{
		l = *lst;
		while (l)
		{
			t = l->next;
			ft_lstdelone(l, del);
			l = t;
		}
		*lst = NULL;
	}
}
