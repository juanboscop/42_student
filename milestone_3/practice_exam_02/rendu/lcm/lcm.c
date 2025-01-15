
unsigned int lcm(unsigned int a, unsigned int b)
{
    if ((int)a < 0 || (int)b < 0)
        return 0;

    if (a == 0 || b == 0)
        return (0);

    unsigned int temp_a = a;
    unsigned int temp_b = b;

    while (temp_b != 0)
    {
        unsigned int temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }

    return (a / temp_a) * b;
}

/*LCM(a,b)= 
a×b /
GCD(a,b)
​
*/