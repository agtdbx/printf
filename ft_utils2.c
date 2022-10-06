/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:02:48 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/06 12:41:12 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned int nb, char *base)
{
	if (nb >= 16)
		print_hex(nb / 16, base);
	ft_putchar_fd(base[nb % 16], 1);
}

static char	*itoa_hex(size_t nb, char *base, char *str)
{
	char	*res;
	int		i;

	if (nb >= 16)
		str = itoa_hex(nb / 16, base, str);
	res = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = base[nb % 16];
	res[i + 1] = '\0';
	free(str);
	return (res);
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
	int				cpt;

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

int	ft_print_pointer(void *p)
{
	char	*res;
	int		len;

	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	res = malloc(sizeof(char));
	if (res == NULL)
		return (0);
	res[0] = '\0';
	res = itoa_hex((size_t)p, "0123456789abcdef", res);
	len = ft_strlen(res);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(res, 1);
	free(res);
	return (len + 2);
}
