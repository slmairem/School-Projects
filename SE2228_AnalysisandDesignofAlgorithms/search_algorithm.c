#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int array[], int n){  //O(n^2)
	int i, j; // 1
	for(i=0; i<n-1; i++){	// O(n)
		for(j=0; j<n-i-1; j++){	// n * O(n)
			if(array[i] > array[i+1]){
				int temp=array[i];
				array[i]=array[i+1];
				array[i+1]=temp;
			}
		}
	}
}

int LinearSearch(int array[], int end, int search){ //O(n+1)
	int i; // 1
	for(i=0 ; i<end ; i++){ // O(end+1)
							// O(n+1)
		if(array[i]==search)
			return i;
	}
	return 0;
}

int BinarySearch(int array[], int end, int search){ //O(n)=log(n)
	BubbleSort(array,end);	// O(end^2)
							// O(n^2)
	int i=1, j=end, location; // 1
	
	while(i<j){	// O(logj)
				// O(logn)
		int mid=(i+j)/2; 
		
		if(search>array[mid]) 
			i=mid+1;
		else
			j=mid;
			
		if(search==array[i])
			location=i;
	
		else 
			location=0;		
	}

	return location; // 1
}

int main(){
	int array[]={2,3,4,5,11};
	printf("Linear Search: %d \n", LinearSearch(array,5,4));
	
	printf("Binary Search: %d ", BinarySearch(array,5,4));
	
	
	//LinearSearch O(n)
	//BinarySearch O(logn)
	//LinearSearch takes more time than BinarySearch because LinearSearch looks all the elements
	//in the array but BinarySearch divides the array
	//O(logn) < O(n) ,  because of that LinearSearch takes more time
	//					and use BinarySearch is more efficient
}
