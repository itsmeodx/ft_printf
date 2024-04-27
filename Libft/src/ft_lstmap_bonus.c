/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsmeodx <itsmeodx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:46:05 by oouaadic          #+#    #+#             */
/*   Updated: 2023/12/02 16:53:45 by itsmeodx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*node;
	void	*ptr;

	first = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			ptr = f(lst->content);
			node = ft_lstnew(ptr);
			if (!node)
			{
				ft_lstclear(&first, del);
				free(ptr);
				return (NULL);
			}
			ft_lstadd_back(&first, node);
			lst = lst->next;
		}
	}
	return (first);
}
