/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-10 11:02:16 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-10 11:02:16 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	spacefinder(const char *str)
{
	if (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (spacefinder(str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

/*int	atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	// skip Whitspaces: check if the string start with any whitespaces 
	while (*str == ' ' || *str == '\n' || *str =='\t' || 
		*str == '\f' || *str == '\r' || *str == '\v' )
		str++;
	
	// Check for sign: if sign is negative multiple it with -1 
	// and got for next charachter otherwise go furtur 
	if (*str == -1)
	{
		sign *= -1;
		str++;
	}
	else 
	{	
		str++;
	}

	// change charachters to integer
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return num * sign;
}
*/
