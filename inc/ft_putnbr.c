/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-02 08:18:09 by mpazouki          #+#    #+#             */
/*   Updated: 2024-07-02 08:18:09 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		char_count;

	nb = n;
	char_count = 0;
	if (nb < 0)
	{
		char_count += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		char_count += ft_putnbr(nb / 10);
		char_count += ft_putchar((nb % 10) + '0');
	}
	else
		char_count += ft_putchar(nb + '0');
	return (char_count);
}
