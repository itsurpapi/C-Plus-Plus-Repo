#include <iostream>
using namespace std;

class Mhs
{
private:
    string nim, nama;
    float ipk;

public:
    void input();
    void cetak();
    string getNim();
    string getNama();
    float getIpk();
    void setIpk(float iipk);
};

void Mhs::input()
{
    cout << "Input NIM  : ";
    cin >> nim;
    cout << "Input Nama : ";
    cin >> nama;
    cout << "Input IPK  : ";
    cin >> ipk;
}
void Mhs::cetak()
{
    cout << "NIM  : " << nim << endl;
    cout << "Nama : " << nama << endl;
    cout << "IPK  : " << ipk << endl;
}
string Mhs::getNim()
{
    return nim;
}
string Mhs::getNama()
{
    return nama;
}
float Mhs::getIpk()
{
    return ipk;
}
void Mhs::setIpk(float iipk)
{
    ipk = iipk;
}

int main()
{
    Mhs Cinta, Rangga;

    Mhs mm[40];
    int jml_mhs;

    cout << "Input jumlah mahasiswa: ";
    cin >> jml_mhs;
    for (int i = 0; i < jml_mhs; i++)
    {
        cout << "Mahasiswa Ke-" << i;
    }

    return 0;
}