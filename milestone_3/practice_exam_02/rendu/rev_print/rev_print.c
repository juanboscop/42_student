/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:02:27 by bosco             #+#    #+#             */
/*   Updated: 2024/11/28 11:15:24 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int	end;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	end = ft_strlen(argv[1]) - 1;
	while (end >= 0)
	{
		write(1, &argv[1][end], 1);
		end--;
	}
	write(1, "\n", 1);
	return (0);
}