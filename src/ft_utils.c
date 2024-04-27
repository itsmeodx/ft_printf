/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:49:57 by oouaadic          #+#    #+#             */
/*   Updated: 2024/02/03 18:41:53 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long long n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_nbrlen_u(unsigned long long n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_isflag(char c)
{
	if (ft_strchr(FLAGS, c))
		return (1);
	return (0);
}

int	ft_istype(char c)
{
	if (ft_strchr(TYPES, c))
		return (1);
	return (0);
}

int	ft_isnumber(char c)
{
	if (ft_strchr(NUMBERS, c))
		return (1);
	return (0);
}
