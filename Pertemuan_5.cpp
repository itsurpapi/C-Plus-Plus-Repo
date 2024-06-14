#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int k, int n, int A[])
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == k)
        {
            return true;
        }
    }
    return false;
}

bool linearSearchSentinel(int k, int n, int a[])
{
    a[n] = k; // Pastikan array a memiliki ruang ekstra untuk sentinel
    int i = 0;
    while (a[i] != k)
    {
        i++;
    }
    return i != n;
}

bool binarySearch(int k, int n, int a[])
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == k)
        {
            return true;
        }
        else if (a[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return false;
}

void searchAndPrintResult(bool (*searchFunc)(int, int, int[]), int key, int size, int arr[])
{
    if (searchFunc(key, size, arr))
    {
        cout << "KEtemuU" << endl;
    }
    else
    {
        cout << "RaonNo" << endl;
    }
}

int main()
{
    int arr[] = {12, 52, 104, 29};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array : ";
    printArray(arr, size);

    int input;
    for (int i = 1; i <= 3; i++)
    {
        cout << i << ". Mau Cari apa? (12, 52, 104, 29): ";
        cin >> input;
        switch (i)
        {
        case 1:
            searchAndPrintResult(linearSearch, input, size, arr);
            break;
        case 2:
            searchAndPrintResult(linearSearchSentinel, input, size, arr);
            break;
        case 3:
            searchAndPrintResult(binarySearch, input, size, arr);
            break;
        }
    }

    return 0;
}
