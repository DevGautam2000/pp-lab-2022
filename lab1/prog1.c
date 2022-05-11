#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//each thread writes all numbers from 0 to MAX_THREAD
void private_clause()
{
	printf("\nNow running PRIVATE clause\n");
	int a, i, thread_id;
#pragma omp parallel for private(a, thread_id)
	for (i = 0; i < omp_get_max_threads(); i++)
	{
		for (a = 0; a < omp_get_max_threads(); a++)
		{
			thread_id = omp_get_thread_num();
			printf("Thread #%d says \"%d\"\n", thread_id, a);
		}
	}
	return;
}
//each thread writes a number between 0 to MAX_THREAD //all threads collectively write all such numbers unquely
void first_private()
{
	printf("\nNow running FIRSTPRIVATE clause\n");
	int i, j, r, thread_id;
	printf("Enter the value till which the threads should loop: ");
	scanf("%d", &r);
	// #pragma omp parallel for firstprivate(r) private(j, thread_id)
	for (i = 0; i < omp_get_max_threads(); i++)
	{
		for (j = 0; j <= r; j++)
		{
			thread_id = omp_get_thread_num();
			printf("Thread #%d says \"%d\"\n", thread_id, i);
		}
	}
	return;
}
//each thread rolls a die
//the number rolled by the last thread is retained
void last_private()
{
	printf("\nNow running LASTPRIVATE clause\n");
	int a = 10, r, thread_id, i;
#pragma omp parallel for firstprivate(a) lastprivate(r) private(thread_id)
	for (i = 0; i < omp_get_max_threads(); i++)
	{
		thread_id = omp_get_thread_num();
		srand(thread_id);
		r = rand() % a + 1;

		printf("Thread #%d rolled a die and got a \"%d\"\n", thread_id, r);
	}
	printf("\nThe value of the die roll is now %d\n", r);
	return;
}
//threads iterate over a range, treating it as a serial construct
void ordered()
{
	printf("\nNow running ORDERED clause\n");
	int i, thread_id;
#pragma omp parallel for ordered private(thread_id)
	for (i = 0; i <= 10; i++)
	{
		thread_id = omp_get_thread_num();
#pragma omp ordered
		printf("Thread #%d says \"%d\"\n", thread_id, i);
	}
	return;
}
//the menu
int menu(void)
{
	printf("(1) - Run the implementation of the PRIVATE clause\n");
	printf("(2) - Run the implementation of the FIRSTPRIVATE clause\n");
	printf("(3) - Run the implementation of the LASTPRIVATE clause\n");
	printf("(4) - Run the implementation of the ORDERED clause\n");
	printf("(0) - Exit the program\n");

	printf("Enter your choice: ");
	int choice = 0;
	scanf("%d", &choice);
	switch (choice)
	{
	case 0:
		break;
	case 1:
		private_clause();
		break;
	case 2:
		first_private();
		break;
	case 3:
		last_private();
		break;
	case 4:
		ordered();
		break;
	default:
		printf("\nInvalid choice");
		choice = 5;
		break;
	}
	return choice;
}

int main(void)
{
	while (menu())
	{
	}
	return 0;
}
// printf("\n\n\n\n");
//print some padding for better clarity