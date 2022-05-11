#include <iostream>
// #include <algorithm>

using namespace std;

#define N 10

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int aux1[n1], aux2[n2];
    int index = 0;
    for (int i = low; i <= mid; ++i)
        aux1[index++] = arr[i];

    index = 0;
    for (int i = mid + 1; i <= high; ++i)
        aux2[index++] = arr[i];

    int i = 0;
    int j = 0;
    int k = low;
    // merge
    while (i < n1 and j < n2)
    {
        if (aux1[i] < aux2[j])
            arr[k++] = aux1[i++];
        else if (aux1[i] > aux2[j])
            arr[k++] = aux2[j++];
        else
        {
            arr[k++] = aux1[i++];
            arr[k++] = aux2[j++];
        }
    }
    while (i < n1)
    {
        arr[k] = aux1[i++];
        k++;
    }

    while (j < n2)
    {
        arr[k] = aux2[j++];
        k++;
    }
}

void mergeSortParallel(int arr[], int low, int high)
{

    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

#pragma omp parallel sections
    {
#pragma omp section
        mergeSortParallel(arr, low, mid);
#pragma omp section
        mergeSortParallel(arr, mid + 1, high);
    }

    // inplace_merge(arr + low, arr + mid + 1, arr + high + 1);
    merge(arr, low, mid, high);
}

void mergeSortSerial(int arr[], int low, int high)
{

    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSortSerial(arr, low, mid);
    mergeSortSerial(arr, mid + 1, high);

    // inplace_merge(arr + low, arr + mid + 1, arr + high + 1);
    merge(arr, low, mid, high);
}
int main()
{

    int arr[N] = {2, 1, 3, 4, 2, 5, 8, 4, 10, 9};
    int arr2[N] = {2, 1, 3, 4, 2, 5, 8, 4, 10, 9};

    int low = 0;
    int high = N - 1;

    mergeSortSerial(arr, low, high);
    mergeSortParallel(arr2, low, high);

    for (auto i : arr)
        cout << i << " ";

    cout << endl;
    for (auto i : arr2)
        cout << i << " ";
    return 0;
}