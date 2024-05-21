/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:20:07 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/12 16:52:33 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_pointer(unsigned long long adr, t_flags *flags)
{
	int		count;

	count = 0;
	flags->hash = 2;
	if ((flags->space == 1) && (flags->sign == 0))
	{
		count += ft_putchar_fd(' ', flags->fd);
		flags->width--;
	}
	if (flags->sign == 0)
		count += ft_print_pointer(adr, "0x", flags);
	else
		count += ft_print_pointer(adr, "+0x", flags);
	return (count);
}

int	ft_print_pointer(unsigned long long adr, char *str, t_flags *flags)
{
	int		count;

	count = 0;
	if (adr == 0)
	{
		count += ft_print_nil(flags);
		return (count);
	}
	if (flags->precision < ft_nbrlen_u(adr, 16))
		flags->precision = ft_nbrlen_u(adr, 16);
	if (flags->hash == 2 && flags->zero == 1)
		count += ft_putstr_fd(str, flags->fd);
	if (flags->minus == 0)
		count += ft_print_width(flags, flags->precision + flags->hash
				+ flags->sign, flags->zero);
	if (flags->hash == 2 && flags->zero == 0)
		count += ft_putstr_fd(str, flags->fd);
	count += ft_print_precision(flags, ft_nbrlen_u(adr, 16));
	count += ft_putnbr_base_key_fd(adr, "0123456789abcdef", 16, flags->fd);
	if (flags->minus == 1)
		count += ft_print_width(flags, flags->precision + flags->hash
				+ flags->sign, flags->zero);
	return (count);
}
