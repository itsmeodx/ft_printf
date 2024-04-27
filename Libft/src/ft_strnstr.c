/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:21:33 by oouaadic          #+#    #+#             */
/*   Updated: 2024/04/27 17:01:44 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = -1;
	little_len = 0;
	while (little[little_len])
		little_len++;
	if (little[0] == 0)
		return ((char *)big);
	while (big[++i] != 0 && len-- >= little_len)
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
	return (NULL);
}
