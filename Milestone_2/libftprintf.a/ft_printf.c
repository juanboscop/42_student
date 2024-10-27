/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:53:50 by jpavia            #+#    #+#             */
/*   Updated: 2024/10/27 15:45:02 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *data_string, ...)
{
	int i;

	i = 0;	
	while (data_string[i] != '\0')
	{
		if (data_string[i] == '%')
		{
			// check_format(data_string, data_string[i]);
		}
		else    
			ft_putchar_fd(data_string[i], 1);
		i++;
	}
	return (0);
}
static void	check_format(char *data, char data_index)
{
	return;
}

int	main(void)
{
	ft_printf("hello");
}
