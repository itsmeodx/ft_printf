/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsmeodx <itsmeodx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:14:15 by oouaadic          #+#    #+#             */
/*   Updated: 2023/12/02 14:21:17 by itsmeodx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;

	i = -1;
	if (s == NULL || f == NULL)
		return (NULL);
	dest = ft_strdup(s);
	if (!dest)
		return (NULL);
	while (dest[++i])
		dest[i] = f(i, dest[i]);
	return (dest);
}
