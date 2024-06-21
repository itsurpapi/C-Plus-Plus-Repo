#include <iostream>
using namespace std;

class Node
{
public:
    string nama;
    Node *next;

    Node()
    {
        nama = "";
        next = NULL;
    }

    Node(string nama)
    {
        this->nama = nama;
        next = NULL;
    }
};
class queue
{
public:
    Node *head;
    Node *tail;
    int kapasitas;

    queue()
    {
        head = NULL;
        tail = NULL;
    }

    queue(int kapasitas)
    {
        this->kapasitas = kapasitas;
        head = NULL;
        tail = NULL;
    }

    bool isempty();
    void enqueue(string nama);
    void dequeue();
    void cetak();
    void enqueuePriority(string nama);
    string peek();
    bool isfull();
    int panjangQ();
};

bool queue::isempty()
{
    return head == NULL;
}

void queue::enqueue(string nama)
{
    Node *temp = new Node(nama);
    if (isempty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void queue::dequeue()
{
    if (!isempty())
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void queue::enqueuePriority(string nama)
{
    Node *temp = new Node(nama);
    if (isempty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

string queue::peek()
{
    return head->nama;
}

void queue::cetak()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << "[ " << current->nama << " | " << current->next << "]";
        if (current->next != NULL)
        {
            cout << " --> ";
        }
        current = current->next;
    }

    cout << endl
         << endl;
}

int queue::panjangQ()
{
    int s = 0;
    Node *current = head;
    while (current != NULL)
    {
        s++;
        current = current->next;
    }
    return s;
}

int main()
{
    queue hokage;
    cout << "Insert Hindia, Noah, feast: \n";
    hokage.enqueue("hindia");
    hokage.enqueue("Noah");
    hokage.enqueue("feast");
    hokage.cetak();

    cout << "Enqueue Priority Telkomsel: \n";
    hokage.enqueuePriority("Telkomsel");
    hokage.cetak();

    cout << "Dequeue: \n";
    hokage.dequeue();
    hokage.cetak();

    cout << "Peek Queue: " << endl;
    cout << "Who is First: " << hokage.peek() << endl
         << endl;

    cout << "Jumlah Queue: " << endl;
    cout << hokage.panjangQ();

    return 0;
}