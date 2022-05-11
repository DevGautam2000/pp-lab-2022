/*
          AUTHOR : GAUTAM CHANDRA SAHA
          DATE & TIME: Wed, February 09,2022 AT 11:08 
          DESCRIPTION:

*/

#include <iostream>
#include <cmath>
#include <vector>
#include<omp.h>

int main()
{

    double sum = 0;
    int size = 100;
    std::vector<int> arr(size, 0); //array of size 100

    for (int i = 0; i < size / 4; i++)
        arr[i] = 1;
    for (int i = size / 4; i < size / 2; i++)
        arr[i] = 2;
    for (int i = size / 2; i < 3 * size / 4; i++)
        arr[i] = 3;
    for (int i = 3 * size / 4; i < size; i++)
        arr[i] = 4;

#pragma omp parallel for shared(sum)

        for (int i = 0; i < size; i++)
        #pragma omp critical
            sum += arr[i];
          
    

    std::cout << "Sum: " << sum;
    return 0;
}
