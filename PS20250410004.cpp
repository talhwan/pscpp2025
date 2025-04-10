#include <iostream>
using namespace std;

struct elem
{
    int value;
};

class MyStack
{
private:
    int maxsize; // 값을 가지고 있을 수 있는 최대값
    int top;     // 현재 배열 순번
    elem *list;  // 배열로 사용할 예정!!
public:
    MyStack(int size = 10);        // 생성자
    ~MyStack() { delete[] list; }; // 소멸자

    void initialize(); // 초기값 세팅 정도!!

    bool isEmpty() const; // 비어있는지 확인
    bool isFull() const;  // 가득찾는지 확인

    void push(const elem &); // 값 넣을때 쓰는 메서드!
    elem *pop();             // 값 꺼내기!!

    void print() const; // 전체 출력
};

MyStack::MyStack(int size)
{
    maxsize = size;
    list = new elem[maxsize];
    // top = -1;
    initialize();
};
void MyStack::initialize()
{
    // 여기는 초기화를 시킬 코드를 넣으면 됩니다!
    top = -1; // 순번을 일단 -1로 설정!! 추가될때마다 1씩 증가시킬 예정!!
}
bool MyStack::isEmpty() const
{
    /*
    1.
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }

    2.
    return (top == -1) ? true : false;
    */
    return (top == -1);
}

bool MyStack::isFull() const
{
    /*
    if (top == maxsize - 1)
    {
        return true;
    }
    else
    {
        return false;
    }

    return (top == maxsize - 1) ? true : false;
    */
    return (top == maxsize - 1);
}

void MyStack::push(const elem &e)
{
    if (!isFull())
    {
        list[++top] = e;
    }
}

elem *MyStack::pop()
{
    if (isEmpty())
    {
        return nullptr;
    }
    return &list[top--];
}
void MyStack::print() const
{
    for (int i = 0; i <= top; i++)
    {
        cout << (i + 1) << ":" << list[i].value << endl;
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