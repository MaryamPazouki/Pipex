/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-03 07:15:07 by mpazouki          #+#    #+#             */
/*   Updated: 2024-07-03 07:15:07 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned	int u)
{
	int	char_count;

	char_count = 0;
	if (u >= 10)
	{
		char_count += ft_putunsigned(u / 10);
	}
	char_count += ft_putchar((u % 10) + '0');
	return (char_count);
}
