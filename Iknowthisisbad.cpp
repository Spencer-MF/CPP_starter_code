#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool repeat = true;

float nums[2] = {0, 0};
string th = "th";
string st = "st";
string nd = "nd";
string rd = "rd";

void intro_diolog();
bool control_switch();
void base_math(string operaton, int opp);
void math_request();
float math_switch(int opp, float n1, float n2);
string root_display(float n1);
string ordinal_check(int n);
string ordinal_indicator(int n);

int main()
{
    intro_diolog();
    while (repeat)
    {
        repeat = control_switch();
    }

    return 0;
}

bool control_switch()
{
    int responce;
    cin >> responce;
    switch (responce)
    {
    case 1:
        base_math("+", 1);
        return true;
    case 2:
        base_math("-", 2);
        return true;
    case 3:
        base_math("*", 3);
        return true;
    case 4:
        base_math("/", 4);
        break;
    case 5:
        base_math("root", 5);
        return true;
    case 6:
        base_math("^", 6);
        return true;
    case 7:
        return false;
    }
    return true;
}

void intro_diolog()
{
    cout << "This is a calulator" << endl
         << endl
         << "Enter a number to pick witch operation you would like to preform" << endl
         << "1: Add" << endl
         << "2: subtract" << endl
         << "3: multiply" << endl
         << "4: devide" << endl
         << "5: nth root" << endl
         << "6: exponential" << endl
         << "7: exit" << endl;
}

void base_math(string operation, int opp)
{
    string indicator;
    math_request();
    float n1 = nums[0];
    float n2 = nums[1];
    float n3 = math_switch(opp, n1, n2);
    if (opp == 5)
    {
        indicator = root_display(n1);
        cout << n1 << indicator << " " << operation << " " << n2 << " = " << n3 << endl;
    }
    else
    {
        cout << n1 << " " << operation << " " << n2 << " = " << n3 << endl;
    }
}

string root_display(float n1)
{
    float is_float;
    int int_checker = static_cast<int>(floor(n1));
    is_float = n1 - int_checker;
    if (is_float)
    {
        return th;
    }
    return ordinal_indicator(int_checker);
}

void math_request()
{
    float n1;
    float n2;
    cout << "enter the first number" << endl;
    cin >> n1;
    cout << "enter the second number" << endl;
    cin >> n2;
    nums[0] = n1;
    nums[1] = n2;
}

float math_switch(int opp, float n1, float n2)
{
    float n3;
    switch (opp)
    {
    case 1:
        n3 = n1 + n2;
        return n3;
    case 2:
        n3 = n1 - n2;
        return n3;
    case 3:
        n3 = n1 * n2;
        return n3;
    case 4:
        n3 = n1 / n2;
        return n3;
    case 5:
        n3 = pow(n2, 1.0 / n1);
        return n3;
    case 6:
        n3 = pow(n2, n1);
        return n3;
    }
    return 01134;
}

string ordinal_indicator(int n)
{
    string indicator;
    indicator = ordinal_check(n);

    return indicator;
}

string ordinal_check(int n)
{
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