#include <stdio.h>
bool is_prime(int n);

int main()
{
    int i;
    for (i = 0; i < 1000; i++)
    {
        if (is_prime(i))
            printf("%d is prime\n", i);
    }
}

bool is_prime(int n)
{
    int i;
    if (n < 2)
    {
        return false;
    }
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}