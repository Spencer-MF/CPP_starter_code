#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<string> eq;
vector<string> opps;
vector<int> operation_converted;
vector<int> opp_order;
vector<int> opp_index_original;
vector<float> numbers;

vector<string> operations = {"+", "-", "*", "/", "root", "^"};
std::map<std::string, int> opp_key;
float nums[2] = {0, 0};

bool repeat = true;
string th = "th";
string st = "st";
string nd = "nd";
string rd = "rd";

void map_init();
void opperation_to_key();
void intro_diolog();
bool control_switch();
void base_math(string operaton, int opp);
void math_request();
float math_switch(int opp, float n1, float n2);
void complex_math();
void expression_input();
void left_to_right();
void order_of_operations();
void operation_str_to_int();
void operation_orderer();
void calculate_ordered_expression();
void final_calc();
void vector_parse();
void clear_vectors();
bool complex_math_choice();

string root_display(float n1);
string ordinal_check(int n);
string ordinal_indicator(int n);

bool isOdd(int n);

void map_init()
{
    opperation_to_key();
}

int main()
{
    map_init();
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
        base_math(operations[0], 0);
        return true;
    case 2:
        base_math(operations[1], 1);
        return true;
    case 3:
        base_math(operations[2], 2);
        return true;
    case 4:
        base_math(operations[3], 3);
        break;
    case 5:
        base_math(operations[4], 4);
        return true;
    case 6:
        base_math(operations[5], 5);
        return true;
    case 7:
        expression_input();
        return true;
    case 8:
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
         << "7: full expression" << endl
         << "8: exit" << endl;
}

void base_math(string operation, int opp)
{
    string indicator;
    math_request();
    float n1 = nums[0];
    float n2 = nums[1];
    float n3 = math_switch(opp, n1, n2);
    if (opp == 4)
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

void expression_input()
{
    bool still_inputing = true;
    string eq_item_input;
    cout << endl
         << "Input the each item in your expression." << endl
         << "Press x to finnish the expression" << endl;
    while (still_inputing)
    {
        cin >> eq_item_input;
        if (eq_item_input == "x")
        {
            still_inputing = false;
        }
        eq.push_back(eq_item_input);
    }
    if (!eq.empty())
    {
        eq.pop_back();
    }
    complex_math();
}

bool complex_math_choice()
{
    string choice;

    cout << "Would you Like to caluate it with the order of operations?" << endl
         << "(If no it will calcuate from left to right)" << endl
         << "y/n" << endl;

    cin >> choice;
    if (choice == "y")
    {
        return true;
    }
    return false;
}

void complex_math()
{
    vector_parse();
    if (complex_math_choice())
    {
        order_of_operations();
        final_calc();
    }
    else
    {
        left_to_right();
    }
    clear_vectors();
}

void vector_parse()
{

    for (size_t i = 0; i < eq.size(); i++)
    {
        if (isOdd(i))
        {
            opps.push_back(eq[i]);
        }
        else
        {
            float num_float = stof(eq[i]);
            numbers.push_back(num_float);
        }
    }
}

void left_to_right()
{
    float n1;
    float n2;
    float n3;
    int opp;
    for (size_t i = 0; i < opps.size(); i++)
    {
        if (!i)
        {
            n1 = numbers[i];
        }
        opp = opp_key[opps[i]];
        n2 = numbers[i + 1];
        n3 = math_switch(opp, n1, n2);
        cout << n1 << " " << opps[i] << " " << n2 << " = " << n3 << endl;
        n1 = n3;
    }
    cout << n3 << endl;
}

void order_of_operations()
{
    int index;
    int opp;
    float n1;
    float n2;
    float n3;
    operation_str_to_int();
    operation_orderer();
}

void operation_str_to_int()
{
    for (size_t i = 0; i < opps.size(); i++)
    {
        operation_converted.push_back(opp_key[opps[i]]);
    }
}

void operation_orderer()
{
    int index_power = 0;
    int index_power_and_mult = 0;
    opp_order.clear();
    opp_index_original.clear();

    for (size_t i = 0; i < operation_converted.size(); i++)
    {
        switch (operation_converted[i])
        {
        case 0:
            opp_order.push_back(0);
            opp_index_original.push_back(i);
            break;
        case 1:
            opp_order.push_back(1);
            opp_index_original.push_back(i);
            break;
        case 2:
            opp_order.insert(opp_order.begin() + index_power_and_mult, 2);
            opp_index_original.insert(opp_index_original.begin() + index_power_and_mult, i);
            index_power_and_mult++;
            break;
        case 3:
            opp_order.insert(opp_order.begin() + index_power_and_mult, 3);
            opp_index_original.insert(opp_index_original.begin() + index_power_and_mult, i);
            index_power_and_mult++;
            break;
        case 4:
            opp_order.insert(opp_order.begin() + index_power, 4);
            opp_index_original.insert(opp_index_original.begin() + index_power, i);
            index_power++;
            index_power_and_mult++;
            break;
        case 5:
            opp_order.insert(opp_order.begin() + index_power, 5);
            opp_index_original.insert(opp_index_original.begin() + index_power, i);
            index_power++;
            index_power_and_mult++;
            break;
        }
    }
    if (operation_converted.size() > 1)
    {
        calculate_ordered_expression();
        operation_orderer();
    }
}

void calculate_ordered_expression()
{
    int index;
    int opp;
    float n1, n2, n3;

    index = opp_index_original[0];
    opp = opp_order[0];
    n1 = numbers[index];
    n2 = numbers[index + 1];
    n3 = math_switch(opp, n1, n2);
    numbers.erase(numbers.begin() + index);
    operation_converted.erase(operation_converted.begin() + index);
    opp_index_original.erase(opp_index_original.begin() + 0);
    opp_order.erase(opp_order.begin() + 0);
    numbers[index] = n3;
    cout << n1 << " " << operations[opp] << " " << n2 << " = " << n3 << endl;
}

void final_calc()
{
    int opp;
    float n1, n2, n3;

    n1 = numbers[0];
    n2 = numbers[1];
    opp = opp_order[0];
    n3 = math_switch(opp, n1, n2);
    cout << n1 << " " << operations[opp] << " " << n2 << " = " << n3 << endl;
}
float math_switch(int opp, float n1, float n2)
{
    float n3;
    switch (opp)
    {
    case 0:
        n3 = n1 + n2;
        return n3;
    case 1:
        n3 = n1 - n2;
        return n3;
    case 2:
        n3 = n1 * n2;
        return n3;
    case 3:
        n3 = n1 / n2;
        return n3;
    case 4:
        n3 = pow(n2, 1.0 / n1);
        return n3;
    case 5:
        n3 = pow(n1, n2);
        return n3;
    }
    return 404;
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

bool isOdd(int n)
{
    n %= 2;
    if (n)
    {
        return true;
    }
    return false;
}

void opperation_to_key()
{
    for (int i = 0; i < 6; i++)
    {
        opp_key[operations[i]] = i;
    }
}

void clear_vectors()
{
    eq.clear();
    opps.clear();
    numbers.clear();
    operation_converted.clear();
    opp_order.clear();
    opp_index_original.clear();
    numbers.clear();
}