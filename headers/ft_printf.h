/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:38:56 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/12 16:56:40 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define FLAGS "#0-+ "
# define NUMBERS "0123456789"
# define TYPES "%cspdiuxX"

typedef struct s_flags
{
	int		hash;
	int		zero;
	int		zero_exist;
	int		minus;
	int		plus;
	int		sign;
	int		space;
	int		width;
	char	type;
	int		init;
	int		offset;
	int		precision;
	int		precision_exist;
	int		fd;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_parse(va_list ap, const char *format, int *i,
					t_flags *flags);
int				ft_parse_type(va_list ap, char c, t_flags *flags);
int				ft_parse_char(char c, t_flags *flags);
int				ft_parse_string(char *str, t_flags *flags);
int				ft_parse_pointer(unsigned long long adr, t_flags *flags);
int				ft_parse_nbr(long nbr, t_flags *flags, int base);
int				ft_parse_hexa(unsigned long nbr, t_flags *flags, char c);
void			ft_parse_flags(char c, t_flags *flags);
void			ft_parse_width(const char *format,
					int *i, t_flags *flags);
void			ft_parse_precision(const char *format,
					int *i, t_flags *flags);
int				ft_print_string(char *str, t_flags *flags);
int				ft_print_str_precision(char *str, t_flags *flags);
int				ft_print_nbr(long nbr, t_flags *flags, int base);
int				ft_putnbr_base_key_fd(unsigned long m, char *key, int base, int fd);
int				ft_print_hexa(unsigned long nbr, char *key, char *hash,
					t_flags *flags);
int				ft_print_pointer(unsigned long long adr, char *str,
					t_flags *flags);
int				ft_print_width(t_flags *flags, int minus, int zero);
int				ft_print_precision(t_flags *flags, int len);
int				ft_print_sign(t_flags *flags);
int				ft_print_0(t_flags *flags);
int				ft_print_nil(t_flags *flags);
int				ft_handle_invalid(t_flags *flags, int *i);
void			ft_init_flags(t_flags *flags);
int				ft_nbrlen(long long n, int base);
int				ft_nbrlen_u(unsigned long long n, int base);
int				ft_isflag(char c);
int				ft_istype(char c);
int				ft_isnumber(char c);

#endif /* FT_PRINTF_H */
