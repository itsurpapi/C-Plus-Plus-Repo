#include <iostream>
using namespace std;

void printArrray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << "== == == == ========" << endl;
}

void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectSort(int arr[], int n)
{
    int min_idx;
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[0];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int a, b, temp;
    a = 20;
    b = 3;
    cout << "Sebelum ditukar:\n"
         << "a=" << a << endl
         << "b=" << b << endl;
    temp = a;
    a = b;
    b = temp;
    cout << "Sebelum ditukar:\n"
         << "a=" << a << endl
         << "b=" << b << endl;
    cout << "================" << endl
         << endl;
    cout << "BubbleSort: " << endl;
    cout << "================" << endl;

    int arrB[] = {12, 65, 43, 89, 54, 23, 58};
    int sB = sizeof(arrB) / sizeof(arrB[0]);

    printArrray(arrB, sB);
    bubbleSort(arrB, sB);
    cout << "Sesudah:" << endl;
    printArrray(arrB, sB);
    cout << endl;

    cout << "SelectSort: " << endl;
    cout << "================" << endl;

    int arrS[] = {1, 5, 7, 4, 9, 10};
    int sS = sizeof(arrS) / sizeof(arrS[0]);

    printArrray(arrS, sS);
    selectSort(arrS, sS);
    cout << "Sesudah:" << endl;
    printArrray(arrS, sS);

    return 0;
}