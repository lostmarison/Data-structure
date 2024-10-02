# 链栈
#### 入队
![LinkQueue1](https://github.com/user-attachments/assets/475dac89-78ad-414e-b857-8910433012c1)
#### 出队
![LinkQueue2](https://github.com/user-attachments/assets/df53bb0a-7897-4b0e-b929-794c6e0fdab0)
![LinkQueue3](https://github.com/user-attachments/assets/d4f57b2a-9834-446a-a77e-78aba9e7d786)
```c++
#include <iostream>
using namespace std;

template <typename T> struct Node {
    T data;
    Node<T>* next;
};

template <typename T> class LinkQueue {
public:
    LinkQueue();
    ~LinkQueue();
    void EnQueue(T x);
    void DeQueue();
    T GetHead() { return front->next->data; }
    int isEmpty() { return (front == rear); }

private:
    Node<T>*front, *rear;
};

template <typename T> LinkQueue<T>::LinkQueue() {
    Node<T>* s = new Node<T>;
    s->next = nullptr;
    front = rear = s; // 将队头指针和队尾指针都指向头结点s
}

template <typename T> LinkQueue<T>::~LinkQueue() {
    while (rear != front) {
        Node<T>* temp = front->next;
        front->next = temp->next;
        if (temp->next == nullptr) { // 出队前队列长度为1
            rear = front;
        }
        delete temp;
    }
}

template <typename T> void LinkQueue<T>::EnQueue(T x) {
    // 尾插法
    Node<T>* s = new Node<T>;
    s->data = x;
    s->next = nullptr; // s成为新的尾结点
    rear->next = s;
    rear = s;
}

template <typename T> void LinkQueue<T>::DeQueue() {
    Node<T>* temp = front->next; // 队列是先进先出，故应删除头结点后的首元结点
    front->next = temp->next;
    if (temp->next == nullptr) { // 出队前队列长度为1
        rear = front;
    }
    delete temp;
}

int main() {
    LinkQueue<int> s;
    for (int i = 0; i < 5; ++i) {
        s.EnQueue(i);
    }
    s.DeQueue();
    s.DeQueue();
    cout << s.GetHead() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}
```
