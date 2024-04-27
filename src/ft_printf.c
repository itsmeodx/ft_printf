/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:37:28 by oouaadic          #+#    #+#             */
/*   Updated: 2024/02/03 21:58:16 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_type(va_list ap, char c, t_flags *flags)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_parse_char(va_arg(ap, int), flags);
	else if (c == 's')
		count += ft_parse_string(va_arg(ap, char *), flags);
	else if (c == 'd' || c == 'i')
		count += ft_parse_nbr(va_arg(ap, int), flags, 10);
	else if (c == 'u')
	{
		flags->sign = 0;
		count += ft_parse_nbr(va_arg(ap, unsigned int), flags, 10);
	}
	else if (c == 'x' || c == 'X')
		count += ft_parse_hexa(va_arg(ap, unsigned int), flags, c);
	else if (c == 'p')
		count += ft_parse_pointer(va_arg(ap, unsigned long long), flags);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_parse(va_list ap, const char *format, int *i, t_flags *flags)
{
	int		count;

	count = 0;
	(*i)++;
	ft_init_flags(flags);
	while (format[*i] && ft_isflag(format[*i]))
	{
		ft_parse_flags(format[*i], flags);
		(*i)++;
	}
	if (format[*i] && ft_isnumber(format[*i]))
		ft_parse_width(format, i, flags);
	if (format[*i] && format[*i] == '.')
		ft_parse_precision(format, i, flags);
	flags->type = format[*i];
	if (!format[*i])
	{
		(*i)--;
		return (0);
	}
	if (ft_istype(format[*i]))
		count += ft_parse_type(ap, format[*i], flags);
	else
		count += ft_handle_invalid(flags, i);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	t_flags	flags;
	va_list	ap;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_parse(ap, format, &i, &flags);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	if (format[0] && flags.type == 0 && flags.init == 1)
		return (-1);
	va_end(ap);
	return (count);
}
