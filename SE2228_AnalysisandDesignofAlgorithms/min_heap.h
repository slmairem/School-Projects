#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *build_min_heap(int *arr, int n);
void min_heapify(int *arr, int n, int i);
int left(int index);
int right(int index);
void swap(int *a, int *b);
void test();


int *build_min_heap(int *arr, int n) {
    int i;

	for(i=n/2 ; i>=0 ; i--)
		min_heapify(arr, n, i);
	
	return NULL;
}

void min_heapify(int *arr, int n, int i) {
	int l=left(i);
	int r=right(i);
	int smallest=i;

	if(l<n && arr[l]<arr[i])
		smallest=l;
	else
		smallest=i;

	if(r<n && arr[r]<arr[smallest])
		smallest=r;
	if(smallest != i){
		swap(&arr[i], &arr[smallest]);
		min_heapify(arr, n, smallest);
	}

}

int left(int index) {
	return ((index+1)*2)-1;
}

int right(int index) {
	return ((index+1))*2;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void test() {
	int *arr= (int*)malloc(sizeof(int)*10);
    
    arr[0] = 16;
    arr[1] = 4;
    arr[2] = 10;
    arr[3] = 14;
    arr[4] = 7;
    arr[5] = 9;
    arr[6] = 3;
    arr[7] = 2;
    arr[8] = 8;
    arr[9] = 1;
	
    int i;
	for(i=0; i<10; i++){
		printf("%d ", arr[i]);
	}

    int *arr2 = build_min_heap(arr, 10);

	for(i=0; i<10; i++){
		printf("%d ", arr2[i]);
	}
}

