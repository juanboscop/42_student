/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:41:02 by bosco             #+#    #+#             */
/*   Updated: 2024/11/27 18:11:49 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char	binary[9];
	int		i;

	binary[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		if (octet & 1)
			binary[i] = '1';
		else
			binary[i] = '0';
		octet >>= 1;
		i--;
	}
	write(1, binary, 8);
}
