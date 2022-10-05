/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:05:46 by aderouba          #+#    #+#             */
/*   Updated: 2022/10/05 17:56:43 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int	ft_printf(const char *, ...);

int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_int(int nb);
int	ft_print_uint(unsigned int nb);

int	ft_print_lowerhex(unsigned int nb);
int	ft_print_upperhex(unsigned int nb);
//int	ft_print_pointer(void *p);

#endif
