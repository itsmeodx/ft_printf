/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:26:31 by oouaadic          #+#    #+#             */
/*   Updated: 2024/04/27 16:49:55 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	i = -1;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	dstlen = 0;
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	if (size <= dstlen)
		return (size + srclen);
	while (++i < size - dstlen - 1 && src[i] != 0)
		dst[dstlen + i] = src[i];
	dst[dstlen + i] = 0;
	return (dstlen + srclen);
}
