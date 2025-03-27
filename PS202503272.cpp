#include <iostream>
using namespace std;

// 구조체 선언 방식
struct
{
    int a;
    string b;
} friend1;

struct friend2
{
    int a;
    int b;
};
friend2 aaa, bbb;

int main()
{
    std::cout << "Hello World!" << endl;
    cout << "Hello World!\n";
    cout << "line break?" << endl;

    int a;
    cin >> a;
    cout << "a : " << a << endl;

    int int_a;
    float float_a;
    double double_a;
    char char_a;
    char array_char_a[2];

    string string_a;

    bool bool_a;
    bool_a = true;

    // 구구단 출력하기
    // 1. for 문 사용
    for (int j = 1; j <= 9; j++)
    {
        for (int i = 1; i <= 9; i++)
        {
            cout << j << "*" << i << "=" << (j * i) << endl;
        }
    }

    // 2. while 문 사용

    return 0;
}