/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:09:15 by oouaadic          #+#    #+#             */
/*   Updated: 2023/11/30 20:54:55 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			j;

	if (dest == src)
		return (dest);
	i = 0;
	j = 0;
	while (i < n)
	{
		ft_memset((unsigned char *)(dest + j), \
		*(unsigned char *)(src + i), sizeof(char) * 1);
		i++;
		j++;
	}
	return (dest);
}
