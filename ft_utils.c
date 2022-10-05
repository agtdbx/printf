/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:57:33 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/05 15:39:37 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 0);
	return (1);
}

int	ft_print_string(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 0);
		return (6);
	}
	ft_putstr_fd(str, 0);
	return (ft_strlen(str));
}

int	ft_print_int(int nb)
{
	long	tmp;
	int		cpt;

	tmp = nb;
	cpt = 0;
	if (tmp < 0)
	{
		tmp *= -1;
		cpt++;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		cpt++;
	}
	cpt++;
	ft_putnbr_fd(nb, 0);
	return (cpt);
}

static void	print_uint(unsigned int nb)
{
	if (nb >= 10)
		print_uint(nb / 10);
	ft_putchar_fd(nb % 10 + '0', 0);
}

int	ft_print_uint(unsigned int nb)
{
	unsigned int	tmp;
	int				cpt;

	cpt = 0;
	tmp = nb;
	while (tmp >= 10)
	{
		tmp /= 10;
		cpt++;
	}
	cpt++;
	print_uint(nb);
	return (cpt);
}
