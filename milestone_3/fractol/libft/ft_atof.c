/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:28:53 by bosco             #+#    #+#             */
/*   Updated: 2024/12/12 20:37:58 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

static const char	*parse_digits(const char *s, double *val)
{
	if (*s >= '0' && *s <= '9')
	{
		*val = *val * 10.0 + (*s - '0');
		return (parse_digits(s + 1, val));
	}
	return (s);
}

static const char	*parse_frac(const char *s, double *val, double *f)
{
	if (*s >= '0' && *s <= '9')
	{
		*val = *val * 10.0 + (*s - '0');
		*f = *f * 10.0;
		return (parse_frac(s + 1, val, f));
	}
	return (s);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	factor;

	result = 0.0;
	sign = 1.0;
	factor = 1.0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	str = parse_digits(str, &result);
	if (*str == '.')
	{
		str++;
		str = parse_frac(str, &result, &factor);
	}
	return ((result / factor) * sign);
}
