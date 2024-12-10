/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-03 07:18:39 by mpazouki          #+#    #+#             */
/*   Updated: 2024-07-03 07:18:39 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hex_upper(unsigned int x)
{
	int		count;

	count = 0;
	if (x >= 16)
	{
		count += ft_hex_upper(x / 16);
	}
	x %= 16;
	if (x < 10)
	{
		ft_putchar(x + '0');
	}
	else
	{
		ft_putchar(x - 10 + 'A');
	}
	return (count + 1);
}
