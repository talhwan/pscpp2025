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
        // front = 0;
        // rear = 0;
        initialize();
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

    if (rear >= maxsize)
    {
        rear = 0;
    }
    list[rear] = elem;
    rear++;
}

int MyCircularQueue::size() const
{
    /*
    0 1 => 1개
    0 5 => 5개
    5 9 => 4개
    5 10(0) => 5개 -5니까..여기다 10 더하기!! 5개
    */
    int tempRear = rear;
    if (tempRear < front)
    {
        tempRear += maxsize - 1;
    }
    return tempRear - front;
}
void MyCircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty !" << endl;
        return;
    }
    front++; // 0_ 1 2 3~~~ 9 => 10
    if (front >= maxsize)
    {
        front = 0;
    }
}
int MyCircularQueue::Front()
{
    return list[front];
}
int MyCircularQueue::Rear()
{
    // 8!! 9!! 10(0)__
    int tempRearOrder = rear - 1; //-1 => 9????
    if (tempRearOrder < 0)
    {
        tempRearOrder += maxsize;
    }
    return list[tempRearOrder];
}

void MyCircularQueue::print()
{

    // 9.. 2 => (12)..
    int tempRear = rear;
    if (tempRear < front)
    {
        tempRear += maxsize;
    }
    for (int i = front; i < tempRear; i++)
    {
        int tempOrder = i;
        if (i > maxsize - 1)
        {
            tempOrder -= maxsize;
        }
        cout << list[tempOrder];
        if (i < tempRear - 1)
        {
            cout << "==> ";
        }
    }
    cout << endl;
}
void MyCircularQueue::printDetail()
{
    cout << endl;
}

int main()
{

    MyCircularQueue myQue;

    cout << "=====Enqueue x 17 (10 ~ 170) =====" << endl;
    for (int i = 0; i < 17; i++)
    {
        myQue.enqueue((i + 1) * 10);
        cout << "size : " << myQue.size() << endl;
        myQue.print();
    }

    myQue.dequeue();
    cout << "size : " << myQue.size() << endl;
    myQue.print();

    myQue.dequeue();
    cout << "size : " << myQue.size() << endl;
    myQue.print();

    myQue.enqueue(1100);
    cout << "size : " << myQue.size() << endl;
    myQue.print();

    for (int i = 0; i < 17; i++)
    {
        myQue.dequeue();
        cout << "size : " << myQue.size() << endl;
        myQue.print();
    }

    myQue.enqueue(1200);
    cout << "size : " << myQue.size() << endl;
    myQue.print();

    myQue.dequeue();
    cout << "size : " << myQue.size() << endl;
    myQue.print();

    return 0;
}