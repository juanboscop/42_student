<<<<<<< Updated upstream
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:39:47 by jpavia            #+#    #+#             */
/*   Updated: 2024/09/17 17:43:55 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalnum(int c)
{
	if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
=======

int ft_isalnum(int c)
{
    if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
>>>>>>> Stashed changes
        return 1;
    1
    else if(c <= '9' && c >= '0')
        return 1;
    else
        return 0;
<<<<<<< Updated upstream
}
=======
}
>>>>>>> Stashed changes
