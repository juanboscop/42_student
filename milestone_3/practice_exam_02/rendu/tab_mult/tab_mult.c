
#include <unistd.h>

void    ft_putnbr(int nb)
{
    char    c;

    if (nb == 0)
    {
        write(1, "0", 1);
        return ;
    }
    if (nb < 0)
    {
        return ;
    }
    if (nb / 10 > 0)
        ft_putnbr(nb / 10);
    c = nb % 10 + '0';
    write(1, &c, 1);
}


int ft_atoi(char *str)
{
    int n;
    int i;

    i = 0;
    n = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            n = n * 10 + (str[i] - '0');
        }
        i++;
    }
    return (n);
}
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int main(int argc, char *argv[])
{
    int my_n;
    int i;

    my_n = 0;
    i = 1;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    my_n = ft_atoi(argv[1]);
    while (i < 10)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(my_n);
        write(1, " = ", 3);
        ft_putnbr(my_n * i);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
