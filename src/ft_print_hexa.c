/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:18:00 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/12 16:38:41 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_hexa(unsigned long nbr, t_flags *flags, char c)
{
	int		count;

	count = 0;
	if (flags->type != 'p')
		flags->sign = 0;
	if (nbr == 0)
		flags->hash = 0;
	if (flags->precision_exist == 1 && flags->precision == 0 && nbr == 0)
	{
		count += ft_print_0(flags);
		return (count);
	}
	if (c == 'x')
		count += ft_print_hexa(nbr, "0123456789abcdef", "0x", flags);
	else if (c == 'X')
		count += ft_print_hexa(nbr, "0123456789ABCDEF", "0X", flags);
	return (count);
}

int	ft_print_hexa(unsigned long nbr, char *key, char *hash, t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->precision < ft_nbrlen(nbr, 16))
		flags->precision = ft_nbrlen(nbr, 16);
	if (flags->hash == 2 && flags->zero == 1)
		count += ft_putstr_fd(hash, flags->fd);
	if (flags->minus == 0)
		count += ft_print_width(flags, flags->precision + flags->hash,
				flags->zero);
	if (flags->hash == 2 && flags->zero == 0)
		count += ft_putstr_fd(hash, flags->fd);
	count += ft_print_precision(flags, ft_nbrlen(nbr, 16));
	count += ft_putnbr_base_key_fd(nbr, key, 16, flags->fd);
	if (flags->minus == 1)
		count += ft_print_width(flags, flags->precision + flags->hash,
				flags->zero);
	return (count);
}

int	ft_putnbr_base_key_fd(unsigned long m, char *key, int base, int fd)
{
	int		count;

	count = 0;
	if (m >= (unsigned long)base)
		count += ft_putnbr_base_key_fd(m / base, key, base, fd);
	count += ft_putchar_fd(key[m % base], fd);
	return (count);
}
