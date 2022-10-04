/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:05:32 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/04 16:20:53 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	//void	*tmp;
	int		i;

	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 0);
		i++;
	}
	/*tmp = va_arg(args, void *);
	while (tmp != NULL)
	{
		tmp = va_arg(args, void *);

	}*/
	va_end(args);
	return (0);
}
