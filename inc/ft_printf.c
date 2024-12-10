/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-27 12:19:40 by mpazouki          #+#    #+#             */
/*   Updated: 2024-06-27 12:19:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	custom_printf(const char *format, va_list args)
{
	size_t	output;

	output = 0;
	if (*format == 'c')
		output += ft_putchar(va_arg(args, int));
	else if (*format == 'p')
		output += ft_putptr(va_arg(args, void *));
	else if (*format == 's')
		output += ft_putstr(va_arg(args, char *));
	else if (*format == 'x')
		output += ft_puthex(va_arg(args, unsigned int));
	else if (*format == 'X')
		output += ft_hex_upper(va_arg(args, unsigned int));
	else if (*format == '%')
		output += ft_putchar('%');
	else if (*format == 'd' || *format == 'i')
		output += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		output += ft_putunsigned(va_arg(args, unsigned int));
	else
	{
		output += ft_putchar('%');
		output += ft_putchar(*format);
	}
	return (output);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	output;

	va_start(args, format);
	output = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				output += custom_printf(format, args);
			else
				output += ft_putchar('%');
		}
		else
		{
			output += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (output);
}

/*
int main()
{

printf("-------------------------Char-------------------------\n");

int c = 1;
printf("count ft_printf: %d\n", ft_printf("Test unsigned integer: %c\n", c));
printf("count by printf: %d\n", printf("Test unsigned integer: %c\n", c));

ft_printf(" %c\n", '0');
ft_printf(" %c\n", '0' - 256);
ft_printf(" %c %c %c\n", '0',0, '1');
ft_printf(" %c %c %c\n", ' ', ' ', ' ');

printf(" %c\n", '0');
printf(" %c\n", '0' - 256);
printf(" %c %c %c\n", '0',0, '1');
printf(" %c %c %c\n", ' ', ' ', ' ');

printf("-------------------------Integer-------------------------\n");


printf("count ft_printf: %d\n", ft_printf("Test unsigned integer: %d\n", 12345));
printf("count by printf: %d\n", printf("Test unsigned integer: %d\n", 12345));

printf("count ft_printf: %d\n", ft_printf("Test unsigned integer: %d\n", 123));
printf("count by printf: %d\n", printf("Test unsigned integer: %d\n", -123));

printf("-------------------------String-------------------------\n");

char *str= NULL;

printf("count ft_printf: %d\n", ft_printf("Test unsigned integer: %s\n", str));
printf("count by printf: %d\n", printf("Test unsigned integer: %s\n", str));

printf("-------------------------unsigned integer-------------------------\n");


printf("count ft_printf: %i\n", 
		ft_printf("Test unsigned integer: %u\n", 1234567890));
printf("count by printf: %i\n", 
		printf("Test unsigned integer: %u\n", 1234567890));


printf("--------Test hexadecimal (lowercase and uppercase)----------------\n");


printf("count ft_printf: %i\n", ft_printf("Test unsigned integer: %x\n", 27));
printf("count by printf: %i\n", printf("Test unsigned integer: %x\n", 27));

printf("count ft_printf: %i\n", ft_printf("Test unsigned integer: %X\n", 27));
printf("count by printf: %i\n", printf("Test unsigned integer: %X\n", 27));


printf("-------------------------Test pointer-------------------------\n");
int xp = 10;
ft_printf("Test pointer: %p\n", &xp);
printf("Test pointer by printf: %p\n", &xp);

ft_printf("test pointer: %p\n", (void *)(intptr_t)-1);
printf("test pointer by printf: %p\n", (void *)(intptr_t)-1);

printf("-------------------------Test percent sign-------------------------\n");
ft_printf("Test percent sign: %%\n");
ft_printf("Test percent sign: %5%\n");

// // Test NULL string
ft_printf("%-s", NULL);

// printf("%16s", "nark nark");

return 0;
}
*/