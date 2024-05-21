/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:16:51 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/12 16:52:05 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_nbr(long nbr, t_flags *flags, int base)
{
	int		count;

	count = 0;
	if (nbr < 0)
	{
		flags->plus = 0;
		flags->sign = 1;
		nbr = -nbr;
	}
	if (flags->precision_exist == 1 && flags->precision == 0 && nbr == 0)
	{
		count += ft_print_0(flags);
		return (count);
	}
	if (flags->precision < ft_nbrlen(nbr, base))
		flags->precision = ft_nbrlen(nbr, base);
	if ((flags->type != 'u') && (flags->space == 1) && (flags->sign == 0))
	{
		count += ft_putchar_fd(' ', flags->fd);
		flags->width--;
	}
	count += ft_print_nbr(nbr, flags, base);
	return (count);
}

int	ft_print_nbr(long nbr, t_flags *flags, int base)
{
	int		count;
	int		sign;

	count = 0;
	sign = 0;
	if (flags->sign == 1)
		sign = 1;
	if (flags->zero == 1 && flags->sign == 1)
	{
		count += ft_print_sign(flags);
		flags->sign = 0;
	}
	if (flags->minus == 0)
		count += ft_print_width(flags, flags->precision + sign,
				flags->zero);
	count += ft_print_precision(flags, ft_nbrlen(nbr, base));
	count += ft_putnbr_base_fd(nbr, base, flags->fd);
	if (flags->minus == 1)
		count += ft_print_width(flags, flags->precision + sign,
				flags->zero);
	return (count);
}
