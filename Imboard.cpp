#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int userchoice;

void dialogue(int text_id);
void userchoices();
bool isPrime(int n);
void mode_switch();
int upToNthPrime(int n);

void dialogue(int text_id)
{
    switch (text_id)
    {
    case 0:
        cout << "This code is made to find primes" << endl
             << "If you would like to find a spesific prime press 1" << endl
             << "If you would like to find all the primes up to a number press 2" << endl;
        userchoices();
        break;
    case 1:
        cout << "What number prime would you like to know" << endl;
        userchoices();
        break;
    }
}

void userchoices()
{
    cin >> userchoice;
}

bool isPrime(int n)
{
    int k;
    double j = pow(n, 1.0 / 2.0);
    for (int i = 2; i < j; i++)
    {
        k = n % i;
        if (k == 0)
        {
            return false;
        }
    }
    if (j != 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int upToNthPrime(int n)
{
    cout << "__________" << endl;
    for (int i = 1; i < n; i++)
    {
        if (isPrime(i))
        {
            cout << i << endl;
        }
    }
    cout << "__________" << endl;
    return 0;
}

void mode_switch()
{
    int n;
    switch (userchoice - 1)
    {
    case (0):
        dialogue(1);
        n = userchoice;
        dialogue(2);
        upToNthPrime(n);
        break;
    }
}

int main()
{
    int text_id = 0;
    dialogue(text_id);
    mode_switch();

    return 0;
}