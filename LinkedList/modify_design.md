修改了remove函数的设计，具体为把删除当前节点的后一个节点改为直接删除当前节点\
修改的代码为：
```python
template <typename T>
void SingleLinkedList<T>::remove()
{
    if (currentPos == nullptr)
    {
        return;
    }
    if(head == currentPos && head != nullptr)
    {
        head = currentPos->next;
        delete currentPos;
        currentPos = head;
        --size;
        return;
    }
    Node* p = head;
    while (p != nullptr)
    {
        if (p->next == currentPos)
        {
            p->next = currentPos->next;
            delete currentPos;
            currentPos = p->next;
            --size;
            return;
        }
        p = p->next;
    }
}
```
如果是空节点，则直接返回\
如果是头节点，则直接删除头节点，并把头节点指向下一个节点\
否则，通过循环找到当前节点的前一个节点，并把前一个节点的next指向当前节点的next，从而实现删除当前节点\
因此，修改设计后的程序输出应该为：\
5\
a &emsp; c &emsp; g\
0 1\
3\
1.5 &emsp; 2 &emsp; 9 &emsp; 4.7 &emsp; 8.8\
1.5 &emsp; 2 &emsp; 8.8 &emsp; 9 &emsp; 4.7\
&emsp;\
&nbsp;\
1.5 &emsp; 2 &emsp; 4.7 &emsp; 8.8 

