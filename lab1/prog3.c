#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    start = clock();

    for (int i = 0; i < 100000; i++)
        printf("A ");

    end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC; // in seconds

    printf("\nIt took %f seconds to execute \n", time_taken);
    return 0;
}
