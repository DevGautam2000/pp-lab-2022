/*
          AUTHOR : GAUTAM CHANDRA SAHA
          DATE & TIME: Wed, February 09,2022 AT 10:50 
          DESCRIPTION:

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <omp.h>

int main()
{

    double sum = 0;
    int size = 100;
    std::vector<int> arr(size, 1); //array of size 100
#pragma omp parallel for shared(sum)
    

        for (int i = 0; i < size; i++)
        #pragma omp critical
            sum += arr[i];
    

    std::cout << "Sum: " << sum;
    return 0;
}
