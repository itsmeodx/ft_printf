/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:02:10 by oouaadic          #+#    #+#             */
/*   Updated: 2024/11/14 18:18:09 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->init = 1;
	flags->hash = 0;
	flags->zero = 0;
	flags->zero_exist = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->sign = 0;
	flags->space = 0;
	flags->width = 0;
	flags->type = 0;
	flags->offset = 0;
	flags->precision = 0;
	flags->precision_exist = 0;
}

void	ft_parse_flags(char c, t_flags *flags)
{
	if (c == '#')
		flags->hash = 2;
	else if (c == '0')
	{
		if (flags->minus == 0)
			flags->zero = 1;
		flags->zero_exist = 1;
	}
	else if (c == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	else if (c == '+')
	{
		flags->plus = 1;
		flags->sign = 1;
		flags->space = 0;
	}
	else if (c == ' ')
		flags->space = 1;
	flags->offset++;
}
