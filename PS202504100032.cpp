#include <iostream>
using namespace std;

struct elem // 구조체!!
{
    int value;
}; // 객체 구조체 모두 ;로 끝나야 함!!!

class MyStack
{
    // 필드도 선언해보고..
private:
    int maxsize; // 받을수 있는 최대 갯수
    int top;     // 현재 배열 순번번
    elem *list;  // 이것은 실제 저장할 배열!!

    // 메서드도 선언해보고..
public:
    MyStack(int size);
    ~MyStack() { delete[] list; };
    void initialize();       // 초기화 해보는 메서드
    bool isEmpty() const;    // 비었는지 확인하는 메서드
    bool isFull() const;     // 최대까지 넣었는지 확인하는 메서드
    void push(const elem &); // 값 집어넣는 메서드
    elem *pop();             // 값 꺼내오는 메서드
    void print();            // 내용 출력 메서드
}; // 객체 구조체 모두 ;로 끝나야 함!!!

// 생성자 구현
MyStack::MyStack(int size)
{
    maxsize = size;
    list = new elem[maxsize];
    initialize();
}
// 초기값 세팅!!
void MyStack::initialize()
{
    top = -1;
}
bool MyStack::isEmpty() const
{
    return (top == -1);
    /*
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    */
}
bool MyStack::isFull() const
{
    return (top == maxsize - 1);
}
void MyStack::push(const elem &e)
{
    if (isFull())
    {
        return;
    }
    top++;
    list[top] = e;
}

elem *MyStack::pop()
{
    if (isEmpty())
    {
        cout << ".....empty" << endl;
        return nullptr; // no object!!!!
    }
    cout << "pop out!! : " << &list[top - 1] << endl;
    return &list[top--];
}

void MyStack::print()
{
    for (int i = 0; i < top + 1; i++)
    {
        cout << (i + 1) << " : " << list[i].value << endl;
    }
}

int main()
{

    int inputSize;
    cin >> inputSize;
    MyStack myStack(inputSize);

    while (true)
    {
        string input;
        int inputVal;
        cin >> input;
        if (input == "push")
        {
            cin >> inputVal;
            elem e;
            e.value = inputVal;
            myStack.push(e);
        }
        else if (input == "pop")
        {
            myStack.pop();
        }
        else if (input == "print")
        {
            myStack.print();
            break;
        }
    }
    return 0;
}