#include <iostream>
using namespace std;
const int StackSize = 10;

template <typename T> class SeqStack {
public:
    SeqStack() { top = -1; }
    ~SeqStack() {}
    void Push(T x) { data[++top] = x; }
    void Pop() { --top; }
    T GetTop() { return data[top]; }
    bool Empty() { return (top == -1); }

private:
    T data[StackSize]; // 存放栈元素的数组
    int top;           // 栈顶元素在数组中的下标
};

int main() 
{
    SeqStack<int> s;
    for (int i = 0; i < 5; ++i) {
        s.Push(i);
    }
    s.Pop();
    s.GetTop;
    cout << "isEmpty:" << s.Empty();
    return 0;
}