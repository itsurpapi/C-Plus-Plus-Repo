#include <iostream>
using namespace std;

class persegi_panjang
{
public: // acces
   // atribut
   float lebar, panjang;

   persegi_panjang(float p, float l)
   { // constructor
      panjang = p;
      lebar = l;
   }

   // fungsi luas
   float luas()
   {
      return panjang * lebar;
   }
   // fungsi keliling
   float keliling()
   {
      return 2 * (panjang * lebar);
   }

   void setPanjang(float p)
   {
      panjang = p;
   }
   void setLebar(float l)
   {
      lebar = l;
   }
   float getPanjang()
   {
      return panjang;
   }
   float getLebar()
   {
      return lebar;
   }
};

int main()
{
   // Object 1 ================================================
   persegi_panjang member1;
   float luasm, kelilingm; // deklarasi

   // acces member
   member1.panjang = 6;
   member1.lebar = 7;

   cout << "Persegi Panjang 1 \nPanjang \t: "
        << member1.panjang << "\nLebar\t\t: "
        << member1.lebar << endl;

   // call function
   luasm = member1.luas();
   kelilingm = member1.keliling();
   // output function
   cout << "Luasnya adalah\t: " << luasm << endl;
   cout << "Kelilingnya\t: " << kelilingm << endl
        << endl;
   //=========================================================

   // Object 2 ================================================
   persegi_panjang member2(10, 25);
   cout << "Persegi Panjang 2 \nPanjang\t\t: "
        << member2.panjang << "\nLebar\t\t: "
        << member2.lebar << endl;

   // call function
   luasm = member2.luas();
   kelilingm = member2.keliling();

   // output function
   cout << "Luasnya adalah\t: " << luasm << endl;
   cout << "Kelilingnya\t: " << kelilingm << endl
        << endl;
   //=========================================================

   // object 3 ================================================
   persegi_panjang member3; // create object
   member3.setPanjang(11);
   member3.setLebar(69);
   cout << "Persegi Panjang 3 \nPanjang\t\t: "
        << member3.getPanjang() << "\nLebar\t\t: "
        << member3.getLebar() << endl;

   // call function
   luasm = member3.luas();
   kelilingm = member3.keliling();

   // output function
   cout << "Luasnya adalah\t: " << luasm << endl;
   cout << "Kelilingnya\t: " << kelilingm << endl
        << endl;
   //=========================================================

   return 0;
};
