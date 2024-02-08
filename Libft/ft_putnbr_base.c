/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:45:52 by oouaadic          #+#    #+#             */
/*   Updated: 2024/01/28 10:23:49 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long m, int base)
{
	int		count;
	char	*key;

	key = "0123456789abcdef";
	count = 0;
	if (m < 0)
	{
		count += ft_putchar('-');
		m = -m;
	}
	if (m >= base)
		count += ft_putnbr_base(m / base, base);
	count += ft_putchar(key[m % base]);
	return (count);
}
