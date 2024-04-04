#include <stdio.h>

void weirdSort(int arr[], int i)
{
	int j, k, max=arr[0], min=arr[0], indexMin=0, indexMax=1, temp;
	for(j=0 ; j<i ; j=j+1)
	{
		for(k=j ; k<i ; k=k+1)
		{
			if (min >= arr[k] && k%2==0)
			{
				min = arr[k];
				indexMin = k;
			}
			if(max <= arr[k] && k%2==1)
			{
				max = arr[k];
				indexMax = k;
			}
		}
		
		if (j%2==0)
		{
			temp = arr[j];
			arr[j] = min;
			arr[indexMin] = temp;
		}
		else
		{
			temp = arr[j];
			arr[j] = max;
			arr[indexMax] = temp;
		}
		
		max = arr[j+1];
		min = arr[j+1];	
	}	
}

void readArray(int arr[], int i)
{
	int j;
	for(j=0 ; j<i ; j=j+1)
	{
		printf("Enter %d. input:", j+1);
		scanf_s("%d", &arr[j]);
	}
	
}

void printArray(int arr[], int i)
{
	int j;
	for (j=0 ; j<i ; j=j+1)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
}


void weirdPrint(int arr[], int i)
{
	int j;
	for(j=0 ; j<i ; j=j+2)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
	for(j=1 ; j<i ; j=j+2)
	{
		printf("%d ", arr[j]);
	}
}


int main()
{
	int arr[10];
	int i=10;
	
    readArray(arr, i);
    weirdSort(arr, i);
    printArray(arr, i);
    weirdPrint(arr, i);
	return 0;
}
