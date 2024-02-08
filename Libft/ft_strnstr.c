/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:21:33 by oouaadic          #+#    #+#             */
/*   Updated: 2023/11/12 22:10:33 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = -1;
	little_len = ft_strlen(little);
	if (little[0] == 0)
		return ((char *)big);
	while (big[++i] != 0 && len-- >= little_len)
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
	return (NULL);
}
