#include <iostream>
using namespace std;

int faktorial(int angka)
{
   int sum = 1, i;
   for (i = 1; i <= angka; i++)
   {
      sum = i * sum;
   }
   return sum;
};

int main()
{
   int angka, sum;
   cout << "Masukan: ";
   cin >> angka;
   faktorial(angka);
   cout << sum;

   return 0;
}