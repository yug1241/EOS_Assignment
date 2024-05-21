/*1. Create a thread to sort given array of 10 integers using selection sort. Main thread should print the result after sorting is completed. */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

	void selection_sort(short arr[], int length){
		for(int i = 0 ; i < length - 1 ; i++)
		{
			for(int j = i + 1 ; j < length ; j++)
			{ 
				if(arr[i] > arr[j]) 
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}

		}
}

// step 1: implement thread function
void* sort_arr(void *param) {
	int *arr = (int*)param;
	// code to sort array
		void selection_sort(short arr[], int length);
	return NULL;
}
//void selection_sort(short arr[], int length);
int main() 
{
	int ret;
	int arr1[10] = {9, 4, 2, 7, 5, 8, 1, 3, 6, 0};



	pthread_t a1;
	ret = pthread_create(&a1, NULL, sort_arr, arr1);
	if(ret < 0)
	{
		perror("pthread_create() failed");
		_exit(0);
	}
	pthread_join(a1, NULL);

	printf("Sorted array: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	return 0;
}
