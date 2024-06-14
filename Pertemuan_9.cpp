#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        // data atribut diisi dengan inputan data
        // this digunakan karena nama variabel atribut dan var. inputan sama
        // Node(int value){ , maka data = value;
        this->next = NULL;
    }
};

class Linkedlist
{
private:
    Node *head;
    Node *tail;

public:
    Linkedlist()
    { // konstruktor defaul
        head = NULL;
        tail = NULL;
    }

    void Linkedlist::insertDepan(int value)
    {
        Node *temp = new Node(value); // konstruktor inputan

        if (head == NULL)
        { // jika list kosong
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void Linkedlist::cetak()
    {
        Node *temp = new Node;
        temp = head;
        while (temp != NULL)
        {
            // cout << temp->data << " ";
            if (temp->next != NULL)
            { // jika tidak di node terakhir
                cout << "[" << temp->data << "|" << temp->next << "] --> ";
            }
            else
            { // jika di node terakhir
                cout << "[" << temp->data << "|" << temp->next << "]";
                // di cpp, jika mencetak NULL, maka akan tampil 0
            }
            temp = temp->next;
        }
        cout << endl;
    }
    void Linkedlist::insertBelakang(int value)
    {
        Node *temp = new Node; // konstruktor default
        temp->data = value;

        if (head == NULL)
        { // jika list kosong
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void Linkedlist::hapusDepan()
    {
        Node *temp = new Node;
        temp = head;
        head = head->next;
        delete temp;

        cetak(); // opsional
    }
    void Linkedlist::hapusBelakang()
    {
        Node *current = new Node;
        Node *previous = new Node;
        current = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;

        cetak(); // opsional
    }
    int Linkedlist::hitungNode()
    {
        int s = 0;
        Node *temp = new Node;
        temp = head;
        while (temp != NULL)
        {
            s++;
            temp = temp->next;
        }
        return s;
    }
    bool Linkedlist::searchData(int k)
    {
        // LinearSearch + Break
        bool found = false;
        Node *temp = new Node;
        temp = head;
        while (temp != NULL)
        {
            if (temp->data == k)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
    bool Linkedlist::searchData2(int k, int n)
    {
        // LinearSearch + Break
        bool found = false;
        Node *temp = new Node;
        temp = head;

        for (int i = 1; i <= n; i++)
        {
            if (temp->data == k)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
    void Linkedlist::insertMid(int value, int n)
    {
        int mid = (n + 1) / 2;
        Node *temp = new Node(value);
        Node *current = head;
        for (int i = 1; i < mid; i++)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }

    void Linkedlist::hapusMid(int n)
    {
        int mid = (n + 1) / 2;

        Node *current = head;
        Node *previous = head;

        for (int i = 1; i < mid; i++)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        current->next = NULL;
        delete current;
    }

    void Linkedlist::insertAfter(int nodeNya, int value)
    {

        Node *temp = new Node(value);
        Node *current = head;

        while (current != NULL && current->data != nodeNya)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            temp->next = current->next;
            current->next = temp;
            if (temp->next == NULL)
            {
                tail = temp;
            }
        }
    }
    void Linkedlist::insertBefore(int nodeNya, int value)
    {

        Node *temp = new Node(value);
        Node *current = head;
        Node *previous = head;

        while (current != NULL && current->data != nodeNya)
        {
            previous = current;
            current = current->next;
        }

        if (current != NULL)
        {

            if (current == head)
            {
                temp->next = current;
                head = temp;
            }
            else
            {
                previous->next = temp;
                temp->next = current;
            }
        }
    }
};

int main()
{
    cout << "Single Linked List Manual" << endl;
    Node *head = new Node; // memanggil konstruktor default
    head->data = 100;
    head->next = new Node; // memanggil konstruktor default
    head->next->data = 84;
    head->next->next = new Node(5); // memanggil konstruktor inputan

    // proses cetak
    Node *temp = new Node;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "\nSingle Linked List menggunakan class Linkedlist" << endl;
    Linkedlist sll;
    cout << "insertDepan(100)\n";
    sll.insertDepan(100);
    sll.cetak();
    cout << "\ninsertDepan(1)\n";
    sll.insertDepan(1);
    sll.cetak();
    cout << "\ninsertBelakang(5)\n";
    sll.insertBelakang(5);
    cout << "Nodenya ada berapa? " << sll.hitungNode() << endl;
    cout << "Apakah ada data 100? " << sll.searchData(100) << endl;
    cout << "Apakah ada data 56? " << sll.searchData(56) << endl;
    int panjangNode = sll.hitungNode();
    cout << "Apakah ada data 100? " << sll.searchData2(100, panjangNode) << endl
         << endl;

    sll.cetak();
    cout << "\nhapusDepan()\n";
    sll.hapusDepan();
    cout << "\nhapusBelakang()\n";
    sll.hapusBelakang();
    cout << "Sekarang nodenya ada berapa? " << sll.hitungNode() << endl;

    // pert 7
    cout << "\n====== Mulai Pertemuan 7 ======\n";
    cout << "\nsll.insertBelakang(1)\n";
    sll.insertBelakang(1);
    sll.cetak();
    cout << "\nsll.insertBelakang(84)\n";
    sll.insertBelakang(84);
    sll.cetak();
    cout << "\nsll.insertBelakang(14)\n";
    sll.insertBelakang(14);
    sll.cetak();

    cout << "\nsll.insertMid(0, sll.hitungNode())\n"; // insert mid
    sll.insertMid(0, sll.hitungNode());
    sll.cetak();
    cout << "\nsll.insertMid(111, sll.hitungNode())\n";
    sll.insertMid(111, sll.hitungNode());
    sll.cetak();

    cout << "\nsll.hapusMid(sll.hitungNode())\n"; // hapus mid
    sll.hapusMid(sll.hitungNode());
    sll.cetak();
    cout << "\nsll.hapusMid(sll.hitungNode())\n";
    sll.hapusMid(sll.hitungNode());
    sll.cetak();

    cout << "\ninsertAfter(100, 23)\n"; // insert after
    sll.insertAfter(100, 23);
    sll.cetak();
    cout << "\ninsertAfter(14, 23)\n";
    sll.insertAfter(14, 23);
    sll.cetak();
    cout << "\ninsertAfter(555, 23)\n";
    sll.insertAfter(555, 23);
    sll.cetak();

    cout << "\ninsertBefore(100, 40)\n"; // insert after
    sll.insertBefore(100, 40);
    sll.cetak();
    cout << "\ninsertBefore(84, 40)\n";
    sll.insertBefore(84, 40);
    sll.cetak();
    cout << "\ninsertBefore(555, 40)\n";
    sll.insertBefore(555, 40);
    sll.cetak();

    return 0;
}