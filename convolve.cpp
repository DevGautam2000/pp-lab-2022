/*
          AUTHOR : GAUTAM CHANDRA SAHA
          DATE & TIME: Wed, May 11,2022 AT 12:49
          DESCRIPTION:

*/

#include <iostream>
#include <stdio.h>
#include <omp.h>

#define KSIZE 3
#define ISIZE 5

using namespace std;

int kernel[KSIZE][KSIZE] = {{1, 0, 1},
                            {0, 1, 0},
                            {1, 0, 1}};

int ans[KSIZE][KSIZE];
int parallel_ans[KSIZE][KSIZE];

int inp[ISIZE][ISIZE] = {{1, 1, 1, 0, 0},
                         {0, 1, 1, 1, 0},
                         {0, 0, 1, 1, 1},
                         {0, 0, 1, 1, 0},
                         {0, 1, 1, 0, 0}};

class Serial
{
public:
    void convolve()
    {
        int ops = ISIZE - 2; // half number of operation to be performed

        // loop for each convolution
        for (int row = 0; row < KSIZE; row++)
            for (int col = 0; col < KSIZE; col++)
            {

                int sum = 0;
                // loop for each matrix to be convoled
                for (int i = row, p = 0; i < ops + row; i++, p++)
                    for (int j = col, l = 0; j < ops + col; j++, l++)
                        sum += inp[i][j] * kernel[p][l];

                // in ans
                ans[row][col] = sum;
            }

        for (int i = 0; i < KSIZE; i++)
        {
            for (int j = 0; j < KSIZE; j++)
                cout << ans[i][j] << " ";

            cout << endl;
        }
    }
} serial;

class Parallel
{
public:
    void convolve()
    {
        int ops = ISIZE - 2;

#pragma omp parallel for
        for (int row = 0; row < KSIZE; row++)
            for (int col = 0; col < KSIZE; col++)
            {

                int sum = 0;
                for (int i = row, p = 0; i < ops + row; i++, p++)
                    for (int j = col, l = 0; j < ops + col; j++, l++)
#pragma omp critical
                        sum += inp[i][j] * kernel[p][l];

                // in ans
                parallel_ans[row][col] = sum;
            }

        for (int i = 0; i < KSIZE; i++)
        {
            for (int j = 0; j < KSIZE; j++)
                cout << parallel_ans[i][j] << " ";

            cout << endl;
        }
    }
} parallel;

void printExecutionTime(double time, string env)
{
    cout << "\nExecution time in " << env << ": ";
    printf("%0.6f\n\n", time);
}

int main()
{
    cout << "OPEN MP PROGRAM TO CONVOLVE A MATRIX\n\n";

    double start, end;

    start = omp_get_wtime();
    serial.convolve();
    end = omp_get_wtime();

    printExecutionTime(end - start, "serial");

    start = omp_get_wtime();
    parallel.convolve();
    end = omp_get_wtime();
    printExecutionTime(end - start, "parallel");

    return 0;
}

/*

INPUT/OUTPUT:

OPEN MP PROGRAM TO CONVOLVE A MATRIX

4 3 4
2 4 3
2 3 4

Execution time in serial: 0.000041

4 3 4
2 4 3
2 3 4

Execution time in parallel: 0.000005

 */
