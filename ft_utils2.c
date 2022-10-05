/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:02:48 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/05 17:56:53 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned int nb, char *base)
{
	if (nb >= 16)
		print_hex(nb / 16, base);
	ft_putchar_fd(base[nb % 16], 0);
}

int	ft_print_lowerhex(unsigned int nb)
{
	unsigned int	tmp;
	int			cpt;

	cpt = 0;
	tmp = nb;
	while (tmp >= 16)
	{
		tmp /= 16;
		cpt++;
	}
	cpt++;
	print_hex(nb, "0123456789abcdef");
	return (cpt);
}

int	ft_print_upperhex(unsigned int nb)
{
	unsigned int	tmp;
	int			cpt;

	cpt = 0;
	tmp = nb;
	while (tmp >= 16)
	{
		tmp /= 16;
		cpt++;
	}
	cpt++;
	print_hex(nb, "0123456789ABCDEF");
	return (cpt);
}
