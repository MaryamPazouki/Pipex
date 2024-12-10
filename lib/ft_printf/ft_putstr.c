/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-02 08:22:00 by mpazouki          #+#    #+#             */
/*   Updated: 2024-07-02 08:22:00 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		count;
	char	*null_str;

	null_str = "(null)";
	count = 0;
	if (!str)
	{
		while (*null_str)
		{
			ft_putchar(*null_str++);
			count++;
		}
	}
	else
	{
		while (*str)
		{
			ft_putchar(*str++);
			count++;
		}
	}
	return (count);
}
