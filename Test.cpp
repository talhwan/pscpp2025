#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 3;
    int *p = &a;

    /*
    cout << &a << endl; // 0x61ff04 a의 주소값
    cout << p << endl;  // 0x61ff04 p가 바라보고 있는 주소값
    cout << *p << endl; // 3 p가 가리키고 있는 주소에 담긴 값
    cout << &p << endl; // 0x61ff00 p 자체의 주소값
     */

    int *input = new int[5];
    /*
    cout << input << endl;     // 0x11d19f8 input이 바라보고 있는 주소값 => input[0] 의 주소값
    cout << &input[0] << endl; // 0x11d19f8 input[0] 의 주소값

    cout << input[0] << endl; // 18684304 input[0] 에 담긴 값 실제 값
    cout << *input << endl;   // input 배열 처음에 담긴 값 실제 값

    cout << &input << endl;
    */

    int array_int[2] = {0, 2};
    int *pointer_test = array_int;
    /*
    cout << array_int << endl;     // 0x61fef8 array_int 의 주소값
    cout << &array_int << endl;    // 0x61fef8 array_int 의 주소값
    cout << &array_int[0] << endl; // 0x61fef8 array_int[0] 의 주소값
    cout << &array_int[1] << endl; // 0x61fef8 array_int[1] 의 주소값
    cout << *array_int << endl;    // 0 array_int[0] 에 담긴 값 실제 값
    cout << array_int[0] << endl;  // 0 array_int[0] 에 담긴 값 실제 값
     */

    return 0;
}