#include <iostream>
using namespace std;

int main()
{
    // int a = 7;
    // int input_number;
    // std::cout << "Hello World!" << std::endl;
    // cout << "a : " << a << endl;
    // cout << "Please Input Number : ";
    // cin >> input_number;
    // cout << "input_number : " << input_number << endl;
    int int_a = 0;
    float float_a = 0.0;
    double double_a = 0.0;
    char char_a = 'A';
    // char[] array_char_a = ;
    char array_char[2];
    string string_a = "";

    bool bool_a = true;

    int limit_number;
    cin >> limit_number;
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        if (i == limit_number)
        {
            break;
        }
        sum += i;
    }
    cout << "sum : " << sum << endl;

    // 1단부터 9단까지 구구단!
    // 1. for 문으로 구현
    // 2. while 문으로 구현

    for (int j = 1; j <= 9; j++)
    {
        for (int i = 1; i <= 9; i++)
        {
            cout << j << "*" << i << "=" << (j * i) << endl;
        }
    }

    return 0;
}