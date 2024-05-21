/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:00:36 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/12 16:39:22 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_width(const char *format, int *i, t_flags *flags)
{
	int		width;

	width = 0;
	flags->offset++;
	while (ft_isnumber(format[*i]))
	{
		width = width * 10 + (format[*i] - '0');
		flags->offset++;
		(*i)++;
	}
	flags->width = width;
	if (!format[*i - 1])
		(*i)--;
}

int	ft_print_width(t_flags *flags, int size, int zero)
{
	int		count;
	int		width;

	count = 0;
	width = flags->width;
	while (width - size > 0)
	{
		if (zero == 1)
			count += ft_putchar_fd('0', flags->fd);
		else
			count += ft_putchar_fd(' ', flags->fd);
		width--;
	}
	return (count);
}
