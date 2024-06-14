#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoubleLinkedList
    {
        head = NULL;
        tail = NULL;
    }
    void insertDepan(int value);
    void insertBelakang(int value);
    void cetak();
    void hapusDepan();
    void hapusBelakang();
    int hitungNode();
    bool searchData(int k);
    bool searchData2(int k, int n);
};

void DoubleLinkedList::insertDepan(int value)
{
    Node *temp = new Node(value);

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
int main
{

    return 0;
}