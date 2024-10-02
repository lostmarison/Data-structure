```c++
void LinkList::DeleteMin()
{
    if (first == nullptr || first->next == nullptr)
        return;
    Node *pre, *min, *q;
    // min用于记录最小值位置
    // pre用于记录最小值的前一个位置
    // q用于遍历链表并于min比较
    pre = first, min = first->next, q = min;
    while (q->next != nullptr)
    // 体会q->next的精妙：q->data可以记录pre，q->next->data可以记录min
    {
        if (q->next->data < min->data)
        {
            pre = q;
            min = q->next;
        }
        q = q->next;
    }
    pre->next = min->next;
    delete min;
}

void LinkList::DeleteValue(int mink, int maxk)
{
    if(first == nullptr || first->next == nullptr) return;
    Node *p = first, *q = first->next;
    while (q != nullptr)
    {
        if (q->data > mink && q->data < maxk)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = p->next;
            q = p->next;
        }

    }
}

int LinkList::FindLastkth(int k)
{
    if(first==nullptr||first->next==nullptr) return -1;
    Node *p1=first,*p2=first;
    //p1先走k步,如果p1=first->next,那么实际走了5步
    for(int i=0;i<k;i++){
        if(p1!=nullptr){
            p1=p1->next;
        }
        else{
            throw"长度不够";
        }
    }
    //因为当p1到最后一个元素时，p1,p2依然要往后走
    while(p1!=nullptr){
        p1=p1->next;
        p2=p2->next;
    }
    return p2->data;
}
```
