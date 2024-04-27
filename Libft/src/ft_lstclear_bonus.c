/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsmeodx <itsmeodx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:53:34 by oouaadic          #+#    #+#             */
/*   Updated: 2023/12/01 22:31:49 by itsmeodx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*curr_node;

	if (lst && del)
	{
		next_node = *lst;
		while (next_node)
		{
			curr_node = next_node;
			next_node = next_node->next;
			ft_lstdelone(curr_node, del);
		}
		*lst = NULL;
	}
}
