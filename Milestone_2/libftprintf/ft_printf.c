/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:53:50 by jpavia            #+#    #+#             */
/*   Updated: 2024/10/28 17:20:00 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static void	check_format(char data_index, va_list args);

int	ft_printf(const char *data_string, ...)
{
	int i;
	va_list	args;

	i = 0;
	va_start(args, data_string);
	while (data_string[i] != '\0')
	{
		if (data_string[i] == '%')
			check_format(data_string[++i], args);
		else
			ft_putchar_fd(data_string[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}
static void	check_format(char data_index, va_list args)
{
	if (data_index == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (data_index == 'd' || data_index == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (data_index == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	else if (data_index == '%')
		ft_putchar_fd('%', 1);
	else if (data_index == 'X')
		ft_puthex_upper(va_arg(args, unsigned int));
	else if (data_index == 'x')
		ft_puthex_lower(va_arg(args, unsigned long));
	else if (data_index == 'p')
		ft_putptr(va_arg(args, void *));
	else if (data_index == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
}
/*When using va_arg(args, int) to retrieve the value for %c, you're effectively getting an int, but you want it treated as a char. Casting it to (char) just ensures that ft_putchar_fd gets the correct type and only prints the intended character*/

int	main(void)
{
	// Test 1: Basic string, integer, and character
	ft_printf("Hello, %s%s%s%s! Number: %d, Char: %c\n", "world", "test", "test", "Test" , 42, 'A');
	printf("Hello, %s%s%s%s! Number: %d, Char: %c\n", "world", "test", "test", "test", 42, 'A');
	
	// Test 2: Integer, unsigned integer, and percentage
	ft_printf("Integer: %d, Unsigned: %u, Percent: %%\n", -123, 123456789u);
	printf("Integer: %d, Unsigned: %u, Percent: %%\n", -123, 123456789u);
	// Test 3: Lowercase hex, uppercase hex, and pointer
	int x = 123;
	ft_printf("Hex (lower): %x, Hex (upper): %X, Pointer: %p\n", 48879, 48879, &x);
	printf("Hex (lower): %x, Hex (upper): %X, Pointer: %p\n", 48879, 48879, &x);

	// Test 4: Mix of signed, unsigned, and hex values
	ft_printf("Signed: %i, Unsigned: %u, Hex: %x\n", -2024, 4294967295u, 305419896);
	printf("Signed: %i, Unsigned: %u, Hex: %x\n", -2024, 4294967295u, 305419896);

	// Test 5: String, hex, and pointer
	char *str = "Khan Academy";
	ft_printf("String: %s, Hex: %x, Pointer: %p\n", str, 0x7fffffff, str);
	printf("String: %s, Hex: %x, Pointer: %p\n", str, 0x7fffffff, str);
	
	// Test 6: Multiple characters and hex in uppercase
	ft_printf("Chars: %c %c %c, Hex (upper): %X\n", 'X', 'Y', 'Z', 305419896);
	printf("Chars: %c %c %c, Hex (upper): %X\n", 'X', 'Y', 'Z', 305419896);

	// Test 7: Large numbers with different formats
	ft_printf("Decimal: %d, Unsigned: %u, Hex (lower): %x\n", 2147483647, 4294967295u, 2147483647);
	printf("Decimal: %d, Unsigned: %u, Hex (lower): %x\n", 2147483647, 4294967295u, 2147483647);

	// Test 8: Pointers with string
	ft_printf("Pointer: %p, String: %s\n", &x, "ft_printf is working!");
	printf("Pointer: %p, String: %s\n", &x, "ft_printf is working!");

	// Test 9: Nested format example
	int y = 1024;
	ft_printf("Pointer y: %p, Hex y: %x, Dec y: %d\n", &y, y, y);
	printf("Pointer y: %p, Hex y: %x, Dec y: %d\n", &y, y, y);

	// Test 10: Multiple types in a single line
	ft_printf("Hello %s! Number %i, Unsigned %u, Hex %x, Char %c\n", "user", -54321, 54321, 0xDEAD, 'B');
	printf("Hello %s! Number %i, Unsigned %u, Hex %x, Char %c\n", "user", -54321, 54321, 0xDEAD, 'B');
    
	return (0);
}
