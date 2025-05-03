/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:49:42 by bosco             #+#    #+#             */
/*   Updated: 2024/12/05 10:48:42 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_puthex_lower(unsigned int num);
int	ft_puthex_upper(unsigned int num);
int	ft_putptr(void *ptr);
int	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int	ft_puthex_lower_long(unsigned long num);

#endif