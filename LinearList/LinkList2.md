```c++
#include <iostream>
    using namespace std;

template <typename T>
struct Node // 结点
{
    T data;     // 数据域
    Node<T>* next; // 指针域
};

template <typename T> class LinkList {
public:
    LinkList();
    ~LinkList();
    int Length();
    Node<T>* MoveTo(int pos);           ////用一个指针指向结点
    int Get(int pos);                   // 按位查找值
    int Locate(T x);                    // 按值查找位
    void Head_Insert(T* list, int len); // 头插法
    void Tail_Insert(T* list, int len); // 尾插法
    void Delete(int pos);
    bool Empty();
    void PrintList();

private:
    Node<T>* first;
};

template <typename T> LinkList<T>::LinkList() {
    first = new Node<T>;   // 生成头结点
    first->next = nullptr; // 头结点的指针域置空
}

template <typename T> LinkList<T>::~LinkList() {
    Node<T>* p = first;
    while (first != nullptr) // 释放每一个结点的存储空间
    {
        first = first->next; // first指向被释放结点的下一个结点
        delete p;
        p = first; // 工作指针后移
    }
}

template <typename T> int LinkList<T>::Length() {
    int length = 0;
    Node<T>* p = first->next;
    // 开始，工作指针*p为首元结点，将头结点的指针域(next)指向首元结点
    while (p != nullptr) {
        ++length;
        p = p->next;
    }
    return length;
}

// 这里定义头结点的位置为0，pos=0,1,2,...,length
template <typename T> Node<T>* LinkList<T>::MoveTo(int pos) {
    Node<T>* p = first;
    for (int i = 0; i < pos; i++) // i=0时为头指针
    {
        p = p->next;
    }
    return p;
}

template <typename T> int LinkList<T>::Get(int pos) {
    Node<T>* p = MoveTo(pos);
    return p->data;
}

template <typename T> int LinkList<T>::Locate(T x) {
    Node<T>* p = first->next;
    int pos = 1;
    while (p != nullptr) {
        if (p->data == x) {
            return pos;
        } else {
            p = p->next;
            ++pos;
        }
    }
    return -1; // 查找失败
}

template <typename T> bool LinkList<T>::Empty() { return !Length(); }

/*
头插法，即每次将新结点插入到头结点后
例如:list[]={1,2,3,4,5},链表输出为：5,4,3,2,1
*/
template <typename T> void LinkList<T>::Head_Insert(T* list, int len) {
    first = new Node<T>;
    first->next = nullptr; // 初始化一个空链表
    for (int i = 0; i < len; i++) {
        Node<T>* s = new Node<T>; // 插入数据实质是插入一个新结点
        s->data = list[i];
        s->next = first->next; // 开始时可以假设头结点后有一个结点
        first->next = s;
        // 上两步本质是插入操作
    }
}

/*
尾插法，即每次将新节点插入到上一个结点尾部
例如:list[]={1,2,3,4,5},链表输出为：1,2,3,4,5
*/
template <typename T> void LinkList<T>::Tail_Insert(T* list, int len) {
    first = new Node<T>;
    first->next = nullptr;
    Node<T>* end = first; // 从头节点开始，因为在开始时它是尾节点
    for (int i = 0; i < len; i++) {
        Node<T>* s = new Node<T>;
        s->data = list[i];
        s->next = nullptr; // 新节点的指针域应该指向nullptr，因为它是新的尾节点
        end->next = s;
        end = s;
    }
}

template <typename T> void LinkList<T>::Delete(int pos) {
    Node<T>* p = MoveTo(pos - 1);
    Node<T>* q = p->next;
    p->next = q->next;
    delete q;
}

template <typename T> void LinkList<T>::PrintList() {
    Node<T>* p = first->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int list[] = {1, 2, 3, 4, 5};
    LinkList<int> s;
    // s.Head_Insert(list,5);
    s.Tail_Insert(list, 5);
    s.Delete(3);
    s.PrintList();
    return 0;
}

```
