![CirQueue](https://github.com/user-attachments/assets/1f045585-1988-4c84-8c36-5bbb9f50bf54)
```c++
#include <iostream>
using namespace std;
const int QueueSize = 100;

template <typename T>
class CirQueue
{
public:
    CirQueue();
    ~CirQueue() {}
    void EnQueue(T x);
    void DeQueue();
    T GetHead() { return data[(front + 1) % QueueSize]; } // 不修改头指针}
    bool Empty() { return (front == rear); }

private:
    T data[QueueSize]; // 存放列队元素的数组
    int front, rear;   // 游标，队头和队尾指针且约定front指向队头元素前一个位置，rear指向队尾元素位置
};

template <typename T>
CirQueue<T>::CirQueue()
{
    // 初始化一个空的循环队列只需将队头front和队尾rear同时指向数组的某个位置，一般是数组的高端
    front = rear = QueueSize - 1;
}

template <typename T>
void CirQueue<T>::EnQueue(T x)
{
    rear = (rear + 1) % QueueSize; // 队尾指针在循环意义上加1
    // rear = QueueSize - 1，则开始时rear = 0
    data[rear] = x;
}

template <typename T>
void CirQueue<T>::DeQueue()
{
    front = (front + 1) % QueueSize;
}

int main()
{
    CirQueue<int> s;
    for (int i = 0; i < 5; ++i)
    {
        s.EnQueue(i);
    }
    cout << s.Empty() << endl;
    cout << s.GetHead();
    return 0;
}
```
