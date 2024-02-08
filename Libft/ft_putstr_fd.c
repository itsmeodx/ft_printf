/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:31:44 by oouaadic          #+#    #+#             */
/*   Updated: 2024/01/25 16:09:05 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		count;

	if (fd < 0)
		return (0);
	count = 0;
	i = -1;
	while (s[++i])
		count += ft_putchar_fd(s[i], fd);
	return (count);
}
