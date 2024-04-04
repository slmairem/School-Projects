#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int key, int size){
	int i;
	for(i=0 ; i<size ; i++){
		if(arr[i] == key){
			printf("The key is found.");
			return 0;
		}
	}
	printf("The key is not found");
	return 0;
}

int left(int i){
	return (i+1)*2+1;
}

int right(int i){
	return (i+1)*2;
}

void leftrotate(int arr[],int i){
	arr[right(i)]=arr[i+1];
	arr[i+1]=arr[left(i)];
	arr[right(right(i))]=arr[right(i)];
}

void rightrotate(int arr[],int i){
	arr[left(i)]=arr[i+1];
	arr[i+1]=arr[right(i)];
	arr[left(left(i))]=arr[left(i)];
}

int findindex(int arr[], int key, int size){
	int i;
	int index=0;

	for (int i = 0; i < size ; i++){
		if(key==arr[i]){
			index=i;
			return index;
		}
	}

	return 0;
}

int balancefac(int arr[], int key, int i, int size){
	if(arr[i]==0)
		return 0;
	return findindex(arr[left(i)], key, size) - findindex(arr[right(i)], key, size);
}

int insert(int arr[], int key, int size){
	int i;
	if(arr[0] == 0){
		arr[0] = key;
		return 0;
	}

	for(i=0;i<size;i++){
		if(arr[i] > key && arr[i]==0){
			arr[left(i)]=key;
			break;
		}
		else if(arr[i] < key && arr[i] == 0 ){
			arr[right(i)]=key;
			break;
		}
	}

	int balance=balancefac(arr,key, i,size);

	if(balance==2){
		if(findindex(arr[left(left(i))],key,size) > findindex(arr[left(right(i))],key,size)){
			rightrotate(arr, i);
		}
		else{
			int temp=arr[left(i)];
			leftrotate(temp,i);
			rightrotate(arr,i);
		}
	}

	if(balance==-2){
		if(findindex(arr[right(right(i))],key,size) > findindex(arr[right(left(i))],key,size)){
			leftrotate(arr, i);
		}
		else{
			int temp=arr[right(i)];
			rightrotate(temp,i);
			leftrotate(arr,i);
		}
	}

	return arr[i];
}

int delete(int arr[], int key, int size){
    int i;

	int index=findindex(arr,key,size);

    while(key!=arr[i]){
        i++; 
    }
    arr[i]=0;

    int balance=balancefac(arr,key, i,size);

	if(balance==2){
		if(findindex(arr[left(left(i))],key,size) > findindex(arr[left(right(i))],key,size)){
			rightrotate(arr, i);
		}
		else{
			int temp=arr[left(i)];
			leftrotate(temp,i);
			rightrotate(arr,i);
		}
	}

	if(balance==-2){
		if(findindex(arr[right(right(i))],key,size) > findindex(arr[right(left(i))],key,size)){
			leftrotate(arr, i);
		}
		else{
			int temp=arr[right(i)];
			rightrotate(temp,i);
			leftrotate(arr,i);
		}
	}

	return arr[i];
}

void printarr(int arr[], int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ", arr[i]);
	}
}

int main(void) {
	int arr[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//arr[15]={52,34,72,23,44,62,89,11,27,35,0,61,0,89,93};
	//44,11,34,52,89,62,23,72,93,27,61,35,86

	insert(arr,44,15);
	printarr(arr,15);
	delete(arr,44,15);
	printarr(arr,15);
	return 0;
}







