/*
          AUTHOR : GAUTAM CHANDRA SAHA
          DATE & TIME: Wed, February 09,2022 AT 11:32 
          DESCRIPTION:

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <omp.h>

void parallel_exec(std::vector<int> &arr)
{
    int count = 0;

#pragma omp parallel 
{
        double sum = 0;
        for (int i = 0; i < arr.size(); i++)
        #pragma omp critical
            sum += arr[i];

        std::cout << "sum for core " << ++count << ": " << sum << std::endl;
}   
}

int main()
{

    int size = 100000;
    std::vector<int> arr(size, 3);
    parallel_exec(arr);
    return 0;
}
