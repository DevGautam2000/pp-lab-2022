#include <stdio.h>
#include <omp.h>
#include <iostream>

using namespace std;

#define out(x) cout << #x << " => " << x << endl;
void sumOfArray(int arr[], int n)
{
    int sum = 0;

#pragma omp parallel
    for (int i = 0; i < n; i++)
#pragma omp critical
        sum += arr[i];
    out(sum);
}
int main()
{

    const int size = 100;
    int arr[100];

    int index = 0;
    for (auto i : arr)
        arr[index++] = 1;

    sumOfArray(arr, size);

    return 0;
}