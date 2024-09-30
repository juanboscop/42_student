/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:27:22 by bosco             #+#    #+#             */
/*   Updated: 2024/09/25 15:37:47 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int   word_count(char  const *word, char c);    
void free_memory(char **result, int words);
char *allocate_word(char const *s, int flag, int i;);

char **ft_split(char const *s, char c)
{
    int words;
    int j;
    char **result;
    int i;
    int flag;

    words = word_count(s, c);
    if (!s || !(result = (char **)malloc((words + 1) * sizeof(char *))))
        return NULL;
    i = 0;
    j = 0;
    while (s[i] != '\0' && j < words)
    {
        while (s[i] == c && s[i] != '\0')
            i++;
        flag = i;
        while (s[i] != c && s[i] != '\0')
            i++;
        result[j] = allocate_word(s, flag, i);
        if (!result[j])
            return free_memory(result, j), NULL;
        j++;
    }
    result[j] = '\0';
    return result;
}
void free_memory(char **result, int words)
{
    int i = 0;
    while (i < words)
    {
        free(result[i]);
        i++;
    }
    free(result);
}
char *allocate_word(char const *s, int flag, int i;)
{
    int k;
    char *word;

    word = (char *)malloc((i - flag + 1)* sizeof(char));
    if(!word)
        return NULL;
    k = 0;
    while(flag < i)
        word[k++] = s[flag++];
    word[k] = '\0';
    return word;
}

int word_count(char const *s, char c) {
    int i = 0;
    int count = 0;
    int in_word = 0;

    while(s[i] != '\0')
    {
        if(s[i] != c && in_word == 0)
        {
            count++;
            in_word = 1;
        }
        else if(s[i] == c)
            in_word = 0;
        i++;
    }
    if(s == NULL || c == NULL)
        return NULL;
    return count;
}
