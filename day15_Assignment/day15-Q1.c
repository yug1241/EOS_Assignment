/*1. Create a thread to sort given array of 10 integers using selection sort. Main thread should print the result after sorting is completed. */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void selection_sort(int arr[], int length)
{
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
	int length = 10;              // Length of the array
	selection_sort(arr, length);  // Call the selection sort function

	return NULL;
}

int main() 
{
	int ret;
	int arr1[10] = {19, 64, 24, 87, 99, 88, 12, 36, 69, 90};



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
