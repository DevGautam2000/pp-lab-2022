/*
          AUTHOR : GAUTAM CHANDRA SAHA
          DATE & TIME: Wed, February 09,2022 AT 11:32 
          DESCRIPTION:

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <omp.h>

double parallel_exec(std::vector<int> &arr, double sum)
{
    double itime, ftime, exec_time;
    itime = omp_get_wtime();
#pragma omp parallel for shared(sum)

        for (int i = 0; i < arr.size(); i++)
        #pragma omp critical
            sum += arr[i];
    

    // Required code for which execution time needs to be computed

    ftime = omp_get_wtime();
    exec_time = ftime - itime;

    std::cout << "Execution time of parallel environment: " << exec_time;

    return exec_time;
}

double serial_exec(std::vector<int> &arr, double sum)
{

    double itime, ftime, exec_time;
    itime = omp_get_wtime();

    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];

    // Required code for which execution time needs to be computed

    ftime = omp_get_wtime();
    exec_time = ftime - itime;

    std::cout << "Execution time of serial environment: " << exec_time;

    return exec_time;
}

int main()
{

    double sum = 0;
    int size = 100000;
    std::vector<int> arr(size, 2);
    double pe = parallel_exec(arr, sum);

    std::cout << std::endl;
    double se = serial_exec(arr, sum);

    std::cout << "\nThe differences of execution times in both environment: " << pe - se << std::endl;

    return 0;
}
