#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class LinkedStack
{
private:
    Node *stacktop;

public:
    LinkedStack();
    ~LinkedStack();
    void initialize();
    bool isEmpty() const;
    void push(const int);
    void pop();
    int peek() const;
    void printAll() const;
};

LinkedStack::LinkedStack()
{
    stacktop = nullptr;
}
LinkedStack::~LinkedStack()
{
    initialize();
}
void LinkedStack::initialize()
{
    while (isEmpty())
    {
        pop();
    }
}
bool LinkedStack::isEmpty() const
{
    return (stacktop == nullptr);
}
void LinkedStack::push(const int num)
{
    Node *node = new Node(num);
    if (isEmpty())
    {
        stacktop = node;
        return;
    }
    // 이미 전에 값이 있었을때!!
    node->next = stacktop; // 새로 생성한 노드 다음값을 이전 탑 값으로!!
    stacktop = node;       // 스택탑 값을 지금 노드로 바꿔치기!!
}
void LinkedStack::pop()
{
    if (isEmpty())
    {
        return;
    }
    Node *tmp = stacktop;
    stacktop = stacktop->next;
    delete tmp;
}
int LinkedStack::peek() const
{
    return stacktop->data;
}
void LinkedStack::printAll() const
{
    if (isEmpty())
    {
        cout << "Stack is empty!!" << endl;
        return;
    }

    int count = 0;
    Node *tmp = stacktop;
    while (tmp != nullptr)
    {
        cout << tmp->data;
        if (tmp->next != nullptr)
        {
            cout << " -> ";
        }
        tmp = tmp->next;
        count++;
    }
    cout << " (" << count << " nodes)" << endl;
}

int main()
{
    LinkedStack *linkedStack = new LinkedStack();
    string input;
    int inputVal;
    while (1)
    {

        cin >> input;
        if (input == "push")
        {
            cin >> inputVal;
            linkedStack->push(inputVal);
        }
        else if (input == "pop")
        {
            linkedStack->pop();
        }
        else if (input == "peek")
        {
            cout << linkedStack->peek() << endl;
        }
        else if (input == "print")
        {
            linkedStack->printAll();
        }
        else if (input == "clear")
        {
            linkedStack->initialize();
        }
        else if (input == "q")
        {
            cout << "Bye!";
            break;
        }
    }

    delete linkedStack;

    return 0;
}