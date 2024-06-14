#include <iostream>
#include <string>
using namespace std;

class NodeStack
{
public:
    int tahun;
    string judul,
        penulis;
    NodeStack *Next;

    NodeStack()
    {
        judul = "";
        penulis = "";
        tahun = 0;
        Next = NULL;
    }
    NodeStack(string judul, string penulis, int tahun)
    {
        this->judul = judul;
        this->penulis = penulis;
        this->tahun = tahun;
        this->Next = NULL;
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
    void push(string judul, string penulis, int tahun);
    void pop();
    void cetak();
};

bool Stack::empty()
{
    return top == NULL;
}

void Stack::push(string judul, string penulis, int tahun)
{
    NodeStack *temp = new NodeStack(judul, penulis, tahun);
    if (empty()) //  atau bisa dengan (top==NULL)
    {
        top = temp;
    }
    else
    {
        temp->Next = top;
        top = temp;
    }
}

void Stack::pop()
{
    if (!empty())
    {
        NodeStack *temp = top;
        top = top->Next;
        delete temp;
    }
}
void Stack::cetak()
{
    NodeStack *temp = top;
    while (temp != NULL)
    {
        cout << "[ " << temp->judul << " | " << temp->penulis << " | " << temp->tahun << " | " << temp->Next << "]";
        if (temp == top && temp->Next == NULL)
        {
            cout << "  <-TOP";
        }
        else if (temp == top)
        {
            cout << "  <-TOP\n";
            cout << "                 | next\n";
            cout << "                 V\n";
        }
        else if (temp->Next != NULL)
        {
            cout << "\n";
            cout << "                 | next\n";
            cout << "                 V\n";
        }
        temp = temp->Next;
    }
    cout << endl;
}
int main()
{
    Stack bukuferdi;

    cout << "--------Stack Dengan Class--------\n\n";
    bukuferdi.push("Hitomi Tanaka", "Sugi", 2009);
    bukuferdi.push("MsBreew", "Lot", 2009);
    bukuferdi.push("Aoi Sora", "Shin Tae Yong", 2009);

    bukuferdi.cetak();

    cout << "POP----------------------------===\n";

    bukuferdi.pop();
    bukuferdi.cetak();
    return 0;
}