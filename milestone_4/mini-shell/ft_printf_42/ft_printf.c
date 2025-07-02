/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:53:50 by jpavia            #+#    #+#             */
/*   Updated: 2024/10/30 21:27:48 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

static int	check_format(char data_index, va_list args);

int	ft_printf(const char *data_string, ...)
{
	int		i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	va_start(args, data_string);
	while (data_string[i] != '\0')
	{
		if (data_string[i] == '%')
			count += check_format(data_string[++i], args);
		else
			count += ft_putchar_fd(data_string[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

static int	check_format(char data_index, va_list args)
{
	int		count;

	count = 0;
	if (data_index == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (data_index == 'd' || data_index == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (data_index == 'c')
		count += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (data_index == '%')
		count += ft_putchar_fd('%', 1);
	else if (data_index == 'X')
		count += ft_puthex_upper(va_arg(args, unsigned int));
	else if (data_index == 'x')
		count += ft_puthex_lower(va_arg(args, unsigned long));
	else if (data_index == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (data_index == 'u')
		count += ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	return (count);
}
