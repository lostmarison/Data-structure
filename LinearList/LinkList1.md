### 头插法
![Head_Insert](https://github.com/user-attachments/assets/d40ea910-e0c7-4ac4-a884-c684b96cb809)
### 尾插法
![Tail_Insert](https://github.com/user-attachments/assets/2cdcd0f9-42ad-42bf-be47-fdac9af34481)
```c++

#include <iostream>
using namespace std;

struct Node // 结点
{
    int data;   // 数据域
    Node* next; // 指针域
};

class LinkList {
public:
    LinkList();
    ~LinkList();
    int Length();
    Node* MoveTo(int pos);                ////用一个指针指向结点
    int Get(int pos);                     // 按位查找值
    int Locate(int x);                    // 按值查找位
    void Head_Insert(int* list, int len); // 头插法
    void Tail_Insert(int* list, int len); // 尾插法
    void Delete(int pos);
    bool Empty();
    void PrintList();

private:
    Node* first;
};

LinkList::LinkList() {
    Node* first = new Node; // 生成头结点
    first->next = nullptr;  // 头结点的指针域置空
}

LinkList::~LinkList() {
    Node* p = first;
    while (first != nullptr) // 释放每一个结点的存储空间
    {
        first = first->next; // first指向被释放结点的下一个结点
        delete p;
        p = first; // 工作指针后移
    }
}

int LinkList::Length() {
    int length = 0;
    Node* p =
        first
            ->next; // 开始，工作指针*p为首元结点，将头结点的指针域(next)指向首元结点
    while (p != nullptr) {
        ++length;
        p = p->next;
    }
    return length;
}

// 这里定义头结点的位置为0，pos=0,1,2,...,length
Node* LinkList::MoveTo(int pos) {
    Node* p = first;
    for (int i = 0; i < pos; i++) // i=0时为头指针
    {
        p = p->next;
    }
    return p;
}

int LinkList::Get(int pos) {
    Node* p = MoveTo(pos);
    return p->data;
}

int LinkList::Locate(int x) {
    Node* p = first->next;
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

bool LinkList::Empty() { return !Length(); }

/*
头插法，即每次将新结点插入到头结点后
例如:list[]={1,2,3,4,5},链表输出为：5,4,3,2,1
*/
void LinkList::Head_Insert(int* list, int len) {
    first = new Node;
    first->next = nullptr; // 初始化一个空链表
    for (int i = 0; i < len; i++) {
        Node* s = new Node; // 插入数据实质是插入一个新结点
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
void LinkList::Tail_Insert(int* list, int len) {
    first = new Node;
    first->next = nullptr;
    Node* end = first; // 从头节点开始，因为在开始时它是尾节点
    for (int i = 0; i < len; i++) {
        Node* s = new Node;
        s->data = list[i];
        s->next = nullptr; // 新节点的指针域应该指向nullptr，因为它是新的尾节点
        end->next = s;
        end = s;
    }
}

void LinkList::Delete(int pos) {
    Node* p = MoveTo(pos - 1);
    Node* q = p->next;
    p->next = q->next;
    delete q;
}

void LinkList::PrintList() {
    Node* p = first->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int list[] = {1, 2, 3, 4, 5};
    LinkList s;
    // s.Head_Insert(list,5);
    s.Tail_Insert(list, 5);
    s.Delete(3);
    s.PrintList();
    return 0;
}
```
