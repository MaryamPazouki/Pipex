/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-03 07:01:00 by mpazouki          #+#    #+#             */
/*   Updated: 2024-07-03 07:01:00 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	address;
	int					char_count;

	char_count = 0;
	address = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		return (ft_putstr("(nil)"));
	}
	else
	{
		char_count += ft_putstr("0x");
		char_count += ft_puthex(address);
	}
	return (char_count);
}
