/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:45:30 by oouaadic          #+#    #+#             */
/*   Updated: 2024/02/02 18:42:29 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nil(t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->minus == 0)
		count += ft_print_width(flags, 5, 0);
	count += ft_putstr("(nil)");
	if (flags->minus == 1)
		count += ft_print_width(flags, 5, 0);
	return (count);
}

int	ft_print_sign(t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->sign == 1)
	{
		if (flags->plus == 1)
			count += ft_putchar('+');
		else
			count += ft_putchar('-');
	}
	return (count);
}

int	ft_print_0(t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->minus == 1)
		count += ft_print_precision(flags, 1);
	count += ft_print_width(flags, flags->plus, 0);
	if (flags->minus == 0)
		count += ft_print_precision(flags, 1);
	return (count);
}

int	ft_handle_invalid(t_flags *flags, int *i)
{
	int		count;

	count = 0;
	if (flags->type == 0)
		return (0);
	count += ft_putchar('%');
	if (flags->hash == 2)
		count += ft_putchar('#');
	if (flags->space == 1 && flags->plus == 0)
		count += ft_putchar(' ');
	if (flags->plus == 1)
		count += ft_putchar('+');
	if (flags->zero_exist == 1 && flags->minus == 0)
		count += ft_putchar('0');
	if (flags->minus == 1)
		count += ft_putchar('-');
	if (flags->width > 0)
		count += ft_putnbr(flags->width);
	if (flags->precision_exist == 1)
	{
		count += ft_putchar('.');
		count += ft_putnbr(flags->precision);
	}
	(*i)--;
	return (count);
}
