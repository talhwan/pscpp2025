#include <iostream>
using namespace std;

/*
class MyClass {
    int x;   // This is private by default
};

struct MyStruct {
    int x;   // This is public by default
};
*/

struct elem // 정수 value 한개를 저장할 수 있는 구조체!
{
    int value;
}; // 구조체든 클래스든 ;로 마무리!!

class MyStack
{
private:
    int maxsize;
    int top;
    elem *list; // 배열로 관리할 예정!!
public:
    void initialize();
    bool isEmpty() const;
    bool isFull() const; // 멤버 변수를 변경할 수 없음!!
    void push(const elem &);
    elem *pop();
    void print();
    MyStack(int size = 10);
    ~MyStack() { delete[] list; };
}; // 구조체든 클래스든 ;로 마무리!!

int main()
{
    return 0;
}