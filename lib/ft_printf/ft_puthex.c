/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-02 10:15:20 by mpazouki          #+#    #+#             */
/*   Updated: 2024-07-02 10:15:20 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(uintptr_t num)
{
	int	char_count;

	char_count = 0;
	if (num >= 16)
	{
		char_count += ft_puthex(num / 16);
	}
	if (num % 16 <= 9)
		char_count += ft_putchar((num % 16) + '0');
	else
		char_count += ft_putchar((num % 16 - 10) + 'a');
	return (char_count);
}

// int	ft_puthex(unsigned long long num)
// {
// 	if (num >= 16)
// 	{
// 		ft_puthex(num / 16);
// 		ft_puthex(num % 16);
// 	}
// 	else
// 	{
// 		if (num <= 9)
// 			ft_putchar(num + '0');
// 		else
// 			ft_putchar((num - 10) + 'a');
// 	}
// 	return (1);
// }
/* A memory address is represented in hexadecimal format, 
	a base-16 numbering system. 
	This format uses numbers 0-9 and letters A-F, 
	offering a more compact representation than binary.
	*/

	//ft_puthex is a recursive function 
	//that prints an unsigned long long number in hexadecimal format. 
	//It divides the number by 16 recursively to get each digit from right 
	//to left and prints it using ft_putchar.