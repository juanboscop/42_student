/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:53:50 by jpavia            #+#    #+#             */
/*   Updated: 2024/10/09 13:27:46 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int my_printf(const char *data_type, ...)
{
	int i;
	
	while(data_type[i] != '\0')
	{
		if(data_type[i] == '%')
		{
			check_format(data_type, data_type[i]);
		}
		else    
			ft_putchar_fd(data_type[i], 1);
	}
}

