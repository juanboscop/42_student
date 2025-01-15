/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:16:41 by bosco             #+#    #+#             */
/*   Updated: 2024/12/11 21:07:28 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\0');
}


void rev_wstr(char *str)
{
    int i = 0;
    int end;
    int start;

    // Find the end of the string
    while (str[i] != '\0')
        i++;
    end = i;

    while (end > 0)
    {
        // Move `end` to the last character of a word
        while (end > 0 && is_delimiter(str[end - 1]))
            end--;

        // Find the start of the word
        start = end;
        while (start > 0 && !is_delimiter(str[start - 1]))
            start--;

        // Write the word
        write(1, &str[start], end - start);

        // Add a space if there are more words
        if (start > 0)
            write(1, " ", 1);

        // Update `end` to the start of the word
        end = start - 1;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    rev_wstr(argv[1]);
    write(1, "\n", 1);
    return(0);
}