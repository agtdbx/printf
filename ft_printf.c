/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:05:32 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/06 12:48:19 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_param(char pc, char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (c == 'd')
		return (ft_print_int(va_arg(args, int)));
	if (c == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_print_lowerhex(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_print_upperhex(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (c == '%')
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	ft_putchar_fd(pc, 1);
	ft_putchar_fd(c, 1);
	return (2);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nb_char_print;

	va_start(args, str);
	i = 0;
	nb_char_print = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			nb_char_print += print_param(str[i], str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			nb_char_print++;
		}
		i++;
	}
	va_end(args);
	return (nb_char_print);
}
