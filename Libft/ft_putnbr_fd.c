/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:45:52 by oouaadic          #+#    #+#             */
/*   Updated: 2024/01/28 13:13:55 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	m;
	int		count;

	if (fd < 0)
		return (0);
	count = 0;
	m = (long)n;
	if (m < 0)
	{
		count += ft_putchar_fd('-', fd);
		m = -m;
	}
	if (m >= 10)
		count += ft_putnbr_fd(m / 10, fd);
	count += ft_putchar_fd('0' + m % 10, fd);
	return (count);
}
