#include <iostream>
using namespace std;

#define N 10
int count = 1;

void printArr(int arr[])
{
    cout << "ARRAY: ";
    for (int i = 0; i < N; i++)
        cout
            << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int start, int end)
{

    cout << "START: " << start << " | END: " << end << endl;
    int pivot = arr[end]; // end =9, arr[9] = 9
    cout << "PIVOT: " << pivot << endl;
    int i = start - 1; // i = -1

    cout << "i: ";
    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            // {2, 1, 3, 4, 2, 5, 8, 4, 10,9};
            // i=8
        }

        cout << i << " ";
    }
    cout << endl;
    printArr(arr);
    swap(arr[i + 1], arr[end]);
    printArr(arr);
    return i + 1;
}

void quickSortSerial(int arr[], int start, int end)
{
    // start =0 , end = 9
    cout << "EXECUTION " << count++ << "\n_____________\n"
         << endl;
    if (start < end)
    {
        int part = partition(arr, start, end); // part =9
        cout << "PART: " << part << endl
             << endl;
        quickSortSerial(arr, start, part - 1);
        quickSortSerial(arr, part + 1, end);
    }
}
int main()
{

    int arr[N] = {2, 1, 3, 4, 2, 5, 8, 4, 10, 9};
    quickSortSerial(arr, 0, N - 1);

    for (auto i : arr)
        cout << i << " ";
    return 0;
}