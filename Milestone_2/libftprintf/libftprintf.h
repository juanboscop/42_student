/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:49:42 by bosco             #+#    #+#             */
/*   Updated: 2024/10/28 17:10:53 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIBFT_H
# define PRINTFLIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
void	ft_puthex_lower(unsigned long num);
void	ft_puthex_upper(unsigned int num);
void	ft_putptr(void *ptr);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);


#endif