/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:07:24 by bosco             #+#    #+#             */
/*   Updated: 2024/09/19 14:07:11 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *char_num);

int ft_atoi(const char *char_num)
{
    int result;
    int sign;
    int i;
    int digit;

    i = 0;
    sign = 1;
    result = 0;
    while(char_num[i] == ' ')
        i++;
    if(char_num[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(char_num[i] == '+')
        i++;  
    while(char_num[i] >= '0' && char_num[i]<= '9')
    {   
        digit = char_num[i] - '0'; /*o el numero 48*/
        result = result * 10 + digit;
        i++;
    }
    return result * sign;
}

