/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:45:52 by oouaadic          #+#    #+#             */
/*   Updated: 2024/04/27 17:46:28 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	m;
	int		count;
	char	*key;

	if (fd < 0)
		return (0);
	key = "0123456789";
	count = 0;
	m = (long)n;
	if (m < 0)
	{
		count += write(fd, "-", 1);
		m = -m;
	}
	if (m >= 10)
		count += ft_putnbr_fd(m / 10, fd);
	count += write(fd, &key[m % 10], 1);
	return (count);
}

int	ft_putnbr(int n)
{
	long	m;
	int		count;
	char	*key;

	m = (long)n;
	key = "0123456789";
	count = 0;
	if (m < 0)
	{
		count += write(1, "-", 1);
		m = -m;
	}
	if (m >= 10)
		count += ft_putnbr(m / 10);
	count += write(1, &key[m % 10], 1);
	return (count);
}

int	ft_putnbr_base(long m, int base)
{
	int		count;
	char	*key;

	key = "0123456789abcdef";
	count = 0;
	if (m < 0)
	{
		count += write(1, "-", 1);
		m = -m;
	}
	if (m >= base)
		count += ft_putnbr_base(m / base, base);
	count += write(1, &key[m % base], 1);
	return (count);
}
