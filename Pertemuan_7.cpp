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
void sortingIpkDesc(Mhs m[], int n)
{
    int i, j;
    Mhs temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (m[j].getIpk() < m[j + 1].getIpk())
            {
                temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
}
void cetaksemuaMhs(Mhs m[], int n)
{
    cout << "| No | NIM \t\t| Nama \t\t | IPK \t|\n";
    for (int i = 0; i < n; i++)
    {
        cout << "| " << i + 1 << "  | " << m[i].getNim() << "\t\t| " << m[i].getNama() << "\t\t | " << m[i].getIpk() << "\t|\n";
    }
}
bool searchnim(string k, int n, Mhs m[])
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (m[i].getNim() == k)
        {
            found = true;
            break;
        }
    }
    return found;
}
float CariIpkDariNama(string k, int n, Mhs m[])
{
    float ipk_dicari;
    for (int i = 0; i < n; i++)
    {
        if (m[i].getNama() == k)
        {
            ipk_dicari = m[i].getIpk();
            break;
        }
    }
    return ipk_dicari;
}

void analisaMhs(Mhs m[], int n)
{
    float nMax = 0, nMin = 100, jml = 0, nRata;
    int iMax, iMin;
    for (int i = 0; i < n; i++)
    {
        jml += m[i].getIpk();
        if (m[i].getIpk() > nMax)
        {
            nMax = m[i].getIpk();
            iMax = i;
        }
        if (m[i].getIpk() < nMin)
        {
            nMin = m[i].getIpk();
            iMin = i;
        }
    }
    cout << "Analisa IPK: \n";
    cout << "IPK Tertinggi: " << nMax << " diperolah mahasiswa " << m[iMax].getNama() << endl;
    cout << "IPK Terendah : " << nMin << " diperolah mahasiswa 2" << m[iMin].getNama() << endl;
    nRata = jml / n;
    cout << "IPK rata-rata: " << nRata << endl;
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
        cout << "Mahasiswa Ke-" << i + 1 << endl;
        mm[i].input();
    }
    cout << endl;

    cout << "| No | NIM \t\t| Nama \t\t\t | IPK \t|\n";
    for (int i = 0; i < jml_mhs; i++)
    {
        cout << "| " << i + 1 << "  | " << mm[i].getNim() << "\t\t| " << mm[i].getNama() << "\t\t\t | " << mm[i].getIpk() << "\t|\n";
    }

    cout << "Sorting Terbaru" << endl;
    sortingIpkDesc(mm, jml_mhs);
    cout << "| No | NIM \t\t| Nama \t\t | IPK \t|\n";
    for (int i = 0; i < jml_mhs; i++)
    {
        cout << "| " << i + 1 << "  | " << mm[i].getNim() << "\t\t| " << mm[i].getNama() << "\t\t | " << mm[i].getIpk() << "\t|\n";
    }

    int pil, urutan;
    char lanjut;
    float ipk_baru;
    int inputnim;

    do
    {
        cout << "\nPilihan\n1. Ubah IPK mahasiswa\n2. Cari NIM Mahasiswa\n3. Cari Ipk dari nama\n4. Analisa\nMasukan pilihan : ";
        cin >> pil;
        if (pil == 1)
        {
            cout << "Masukkan Urutan: ";
            cin >> urutan;
            urutan--;
            cout << "Masukkan IPK baru: ";
            cin >> ipk_baru;
            // set ipk baru
            mm[urutan].setIpk(ipk_baru);
            cetaksemuaMhs(mm, jml_mhs);
        }
        else if (pil == 2)
        {
            string cari_nim, hasil_cari_nim;
            cout << "Cari NIM : ";
            cin >> cari_nim;
            hasil_cari_nim = (searchnim(cari_nim, jml_mhs, mm) == 1) ? "Exist" : "Not Exist";

            cout << "Mahasiswa " << cari_nim << " " << hasil_cari_nim << endl;
        }

        else if (pil == 3)
        {
            string cari_nama, hasil_cari_nama;
            cout << "Cari Nama : ";
            cin >> cari_nama;
            cout << "Mahasiswa bernama " << cari_nama << " = " << CariIpkDariNama(cari_nama, jml_mhs, mm) << endl;
        }
        else if (pil == 4)
        {
            analisaMhs(mm, jml_mhs);
        }
        else
        {
            cout << "Inputan salah";
        }
        cout << "Apakah ingin lanjut?(y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y');

    return 0;
};
