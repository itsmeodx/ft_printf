/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsmeodx <itsmeodx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:11:15 by oouaadic          #+#    #+#             */
/*   Updated: 2023/12/02 14:52:06 by itsmeodx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_split(char **d)
{
	size_t	i;

	i = 0;
	while (d[i])
		free(d[i++]);
	free(d);
}

static char	**ft_words(char const *s, char c, char **d, int count)
{
	int	i;
	int	word;
	int	len;

	i = 0;
	word = -1;
	len = 0;
	while (++word < count)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		d[word] = ft_substr(s, i - len, len);
		if (!d[word])
		{
			free_split(d);
			return (NULL);
		}
		len = 0;
	}
	return (d);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_getcount(s, c);
	d = (char **)malloc(sizeof(char *) * (count + 1));
	if (!d)
		return (NULL);
	d = ft_words(s, c, d, count);
	d[count] = 0;
	return (d);
}
