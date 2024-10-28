/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:53:50 by jpavia            #+#    #+#             */
/*   Updated: 2024/10/27 20:36:44 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

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
		{
			check_format(data_string[++i], args);
		}
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
	else if(data_index == '%')
		ft_putchar_fd('%', 1);
	return;
}
/*When using va_arg(args, int) to retrieve the value for %c, you're effectively getting an int, but you want it treated as a char. Casting it to (char) just ensures that ft_putchar_fd gets the correct type and only prints the intended character*/

int	main(void)
{
	ft_printf("hello");
}
