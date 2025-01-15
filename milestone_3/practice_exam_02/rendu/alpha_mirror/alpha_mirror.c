/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:32:57 by bosco             #+#    #+#             */
/*   Updated: 2024/12/04 18:56:06 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    
    i = 0;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i] > 0)
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            argv[1][i] = ('a' + 'z') - argv[1][i];
            write(1, &argv[1][i], 1);
        }
        else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            argv[1][i] = ('A' + 'Z') - argv[1][i];
            write(1, &argv[1][i], 1);
        }
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}