/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:45:52 by oouaadic          #+#    #+#             */
/*   Updated: 2024/01/25 15:54:48 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	long	m;
	int		count;

	m = (long)n;
	count = 0;
	if (m < 0)
	{
		count += ft_putchar('-');
		m = -m;
	}
	if (m >= 10)
		count += ft_putnbr(m / 10);
	count += ft_putchar('0' + m % 10);
	return (count);
}
