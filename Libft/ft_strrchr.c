/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsmeodx <itsmeodx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:45:56 by oouaadic          #+#    #+#             */
/*   Updated: 2023/12/01 23:16:50 by itsmeodx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*sp;

	i = -1;
	sp = NULL;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			sp = (char *)&s[i];
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (sp);
}
