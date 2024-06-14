#include <iostream>
using namespace std;
class NodeStack
{
public:
    int value;
    NodeStack *Next;

    NodeStack()
    {
        value = 0;
        Next = NULL;
    }

    NodeStack(int value)
    {
        this->Next = NULL;
        this->value = value;
    }
};

class Stack
{
private:
    NodeStack *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool empty();
    void push(int value);
    void pop();
    void cetak();
};

bool Stack::empty()
{
    return top == NULL;
}

void Stack::push(int value)
{
    NodeStack *temp = new NodeStack(value);
    if (empty())
    {
        top = temp;
    }
    else
    {
        temp->Next = top;
        top = temp;
    }
}
int main()
{

    return 0;
}