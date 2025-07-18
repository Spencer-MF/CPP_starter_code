#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int n);
void looper();
void display();

vector<int> primes;

int main()
{
    looper();
    display();
}

void looper()
{
    int i;
    for (i = 0; i < 1000000; i++)
    {
        if (is_prime(i))
            primes.push_back(i);
    }
}

void display()
{
    for (int i : primes)
        cout << i << endl;
}

bool is_prime(int n)
{
    int i;
    if (n < 2)
    {
        return false;
    }
    for (i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
