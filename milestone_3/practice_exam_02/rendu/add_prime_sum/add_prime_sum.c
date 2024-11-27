/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:14:52 by bosco             #+#    #+#             */
/*   Updated: 2024/11/27 19:22:29 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi_unsigned(char *num)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (num[i] == ' ' || num[i] == '\t')
		i++;
	if (num[i] == '-')
		return (-1);
	while (num[i] >= '0' && num[i] <= '9')
	{
		number = number * 10 + (num[i] - '0');
		i++;
	}
	return (number);
}

int	is_prime(int num)
{
	int	i;
	int	is_prime;

	is_prime = 1;
	i = 2;
	while (i <= (num / 2))
	{
		if (num % i == 0)
			is_prime = 0;
		i++;
	}
	return (is_prime);
}

void	write_int(int num)
{
	char	buffer[12];
	int		i;

	i = 0;
	if (num == 0)
		write(1, "0", 1);
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
		write(1, &buffer[--i], 1);
}

int	main(int argc, char	*argv[])
{
	int	i;
	int	num;
	int	add;

	if (argc != 2 || num == -1)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return (0);
	}
	num = ft_atoi_unsigned(argv[1]);
	i = 2;
	add = 0;
	while (i <= num)
	{
		if (is_prime(i))
			add += i;
		i++;
	}
	write_int(add);
	write(1, "\n", 1);
	return (0);
}
