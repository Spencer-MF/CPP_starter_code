#include <iostream>
using namespace std;

long long factorial(int n);
int number_request();
void display(int in, long long out);

int main()
{
    int in;
    long long out;
    in = number_request();
    out = factorial(in);
    display(in, out);

    return 0;
}

long long factorial(int n)
{
    long long store = 1;
    for (int i = n; i > 0; i--)
    {
        store *= i;
    }
    return store;
}

int number_request()
{
    int n;
    cout << "Please type the number you would like factorialized " << endl;
    cin >> n;
    return n;
}

void display(int in, long long out)
{
    cout << "The factorial of " << in << " is " << out << endl;
}