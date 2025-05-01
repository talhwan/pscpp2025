#include <iostream>
using namespace std;

class MyCircularQueue
{
private:
    int maxsize; // 큐 배열의 최대 크기
    int front;   // 첫 번째 요소 바로 앞 인덱스
    int rear;    // 마지막 요소의 인덱스
    int *list;   // 데이터를 저장할 배열 포인터
public:
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const int &elem);
    void dequeue();
    int Front();
    int Rear();
    int size() const;
    void print();
    void printDetail();

    MyCircularQueue(int n = 10)
    {
        maxsize = n;
        list = new int[maxsize];
        front = 0;
        rear = 0;
    }
    ~MyCircularQueue()
    {
        delete[] list;
    }
};

void MyCircularQueue::initialize()
{
    front = 0;
    rear = 0;
}
bool MyCircularQueue::isEmpty() const
{
    return (size() == 0);
}
bool MyCircularQueue::isFull() const
{
    return (size() == maxsize);
}
void MyCircularQueue::enqueue(const int &elem)
{
    if (isFull())
    {
        cout << "Queue is full !" << endl;
        return;
    }
    else
    {
        if (rear >= maxsize)
        {
            rear = 0;
        }
        list[(rear)] = elem;
        rear++;
    }
}
void MyCircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty !" << endl;
        return;
    }
    front++;
    if (front > maxsize - 1)
    {
        front = 0;
    }
    // 0 1 2 3 4 5 6 7 8 9 (10)
}
int MyCircularQueue::Front()
{
    return list[front];
}
int MyCircularQueue::Rear()
{
    return list[rear];
}
void MyCircularQueue::print()
{
    int tempRear = rear;
    if (tempRear < front)
    {
        tempRear += maxsize;
    }
    for (int i = front; i < tempRear; i++)
    { // 0 1
        int realArrayorder = i;
        if (realArrayorder > maxsize - 1)
        {
            realArrayorder = i - maxsize;
        }
        cout << list[realArrayorder];
        if (i < tempRear - 1)
        {
            cout << " => ";
        }
    }
    cout << endl;
}

int MyCircularQueue::size() const
{
    int tempSize = rear - front; // 리어2 프론트0 2개!! 리어0 프론트9 (1)
    if (tempSize < 0)
    {
        tempSize += maxsize;
    }
    return tempSize;
}

int main()
{

    MyCircularQueue myQue;

    cout << "=====Enqueue x 7 (10 ~ 70) =====" << endl;
    for (int i = 0; i < 17; i++)
    {
        myQue.enqueue((i + 1) * 10);
        myQue.print();
    }

    cout << "=====Dequeue x 3 =====" << endl;
    for (int i = 0; i < 3; i++)
    {
        myQue.dequeue();
    }
    myQue.print();

    myQue.enqueue(1000);
    myQue.print();

    myQue.dequeue();
    myQue.print();

    myQue.enqueue(2000);
    myQue.print();

    return 0;
}