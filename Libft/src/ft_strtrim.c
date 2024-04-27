/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:05:28 by oouaadic          #+#    #+#             */
/*   Updated: 2024/04/27 17:02:20 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char const *set, char c)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	while (s1[end])
		end++;
	while (s1[start] && ft_isinset(set, s1[start]))
		start++;
	while (end > 0 && ft_isinset(set, s1[end - 1]))
		end--;
	len = end - start;
	trimmed = ft_substr(s1, start, len);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
