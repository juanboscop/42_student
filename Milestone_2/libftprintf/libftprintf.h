/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:49:42 by bosco             #+#    #+#             */
/*   Updated: 2024/11/26 17:40:45 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_puthex_lower(unsigned long num);
int	ft_puthex_upper(unsigned int num);
int	ft_putptr(void *ptr);
int	ft_putnbr_unsigned_fd(unsigned int n, int fd);


#endif