#include <iostream>
#include <string>
using namespace std;

string ordinal_check(int n);

int main()
{
    int n;
    string indicator;
    cin >> n;
    cout << ordinal_check(n) << endl;
}

string ordinal_check(int n)
{
    string st = "st";
    string nd = "nd";
    string rd = "rd";
    string th = "th";
    int order1;
    int order2;
    order1 = n % 10;
    order2 = n % 100;
    if (order2 != 11 && order2 != 12 && order2 != 13)
    {
        switch (order1)
        {
        case 1:
            return st;
        case 2:
            return nd;
        case 3:
            return rd;
        }
    }
    return th;
}