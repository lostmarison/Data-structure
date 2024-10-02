#### 入栈：
![StackPush](https://github.com/user-attachments/assets/a9e86209-b2d1-4cf5-b531-cc5edf6fc99c)
#### 出栈：
![StackPop](https://github.com/user-attachments/assets/1220f152-ea3f-45ea-9d1a-494134a9195f)
```c++
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkStack
{
public:
    LinkStack();
    ~LinkStack();
    void Push(T x);
    void Pop();
    T GetTop() { return top->data; }
    bool Empty() { return !top; }
    void PrintStack();

private:
    Node<T> *top; // 栈顶指针即栈链的头指针
};

template <typename T>
LinkStack<T>::LinkStack()
{
    top = nullptr; // 栈链不需要头结点
}

template <typename T>
LinkStack<T>::~LinkStack()
{
    while (top)
    {
        Node<T> *p = nullptr;
        p = top;
        top = top->next;
        delete p; // 删除栈顶
    }
}

template <typename T>
void LinkStack<T>::Push(T x)
{
    Node<T> *s = new Node<T>;
    s->data = x;
    s->next = top;
    top = s;
}

template <typename T>
void LinkStack<T>::Pop()
{
    Node<T> *p = nullptr;
    p = top;
    top = top->next;
    delete p;
}

template <typename T>
void LinkStack<T>::PrintStack()
{
    Node<T> *p = top;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    LinkStack<int> s;
    for (int i = 0; i < 5; ++i)
    {
        s.Push(i);
    }
    s.Pop();
    cout << s.GetTop() << endl;
    s.Push(150);
    s.PrintStack();
    return 0;
}
```
