#include <stdio.h>
#include <omp.h>

int main()
{

    double sum = 0;
#pragma omp parallel
    {

        int i = 0;
        while (i < 4)
        {
            double start, end;
            start = omp_get_wtime();

            if (omp_get_thread_num() == i)
            {
                for (i = 0; i < 25000; i++)
                    printf(" A ");
            }
            end = omp_get_wtime();

            printf("\nFunction used in Core : %d ", omp_get_thread_num());
            printf("\nTime taken by Core %d is : %f ", omp_get_thread_num(), end - start);
            sum += (end - start);
            i++;
        }
    }
    printf("\n Total execution time : %f ", sum);

    return 0;
}
