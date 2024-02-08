/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:22:01 by oouaadic          #+#    #+#             */
/*   Updated: 2023/11/30 18:12:49 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup_str;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	dup_str = (char *)malloc(len);
	if (dup_str == NULL)
		return (NULL);
	ft_memcpy(dup_str, s, len);
	return (dup_str);
}
