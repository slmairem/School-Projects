// do sorting with ascending order you can use any amount of functions 
// But dont change parameter and return type of this functions

// Do big o analyis use T(n) for time, finally calculate
// big O of your algorithm

void swap(char **a, char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

//BubbleSort
void someAlgorithm1(char **words, int n) {
    int i, j;

    for (i=0; i<n-1; i++){ 
        for (j=0; j<n-1-i; j++){ 
            if (strcmp(words[j], words[j+1]) > 0){
                swap(&words[j], &words[j+1]);
            }
        }
    }
}
// 1. Big O analysis someAlgorithm1
// O(n^2)

//Quicksort
void someAlgorithm2(char **words, int n) {
    int i, pivot = 0;

	if (n <= 1) 
		return;
	
	for (i=0; i<n ; i++) { //n
		if (strcmp(words[i], words[n-1]) < 0){
			pivot=pivot+1;
            swap(&words+i, &words+pivot);
        }		
	}

	swap(words+pivot, words+n-1);

	someAlgorithm2(words, pivot++);			
	someAlgorithm2(words+pivot, n-pivot);
}
// 2. Big O analysis someAlgorithm2
//O(nlogn)

void heapify(char **words, int n, int i) {
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

    if(left<n && words[left]>words[largest])
        largest = left;

    if(right<n && words[right]>words[largest])
        largest = right;
    
    if (largest != i) {
      swap(&words[i], &words[largest]);
      heapify(words, n, largest);
  }
}

void someAlgorithm3(char **words, int n) {
    int i;
    for (i=n/2 - 1; i>=0; i--)
      heapify(words, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
        swap(&words[0], &words[i]);
        heapify(words, i, 0);
    }
}
// 3. Big O analysis someAlgorithm3
//O(nlogn)


// Questions and Answers write minimum 1-2 sentences for each question

// 1. Which algorithm is the fastest for ascending order? Why?
// 2. Which algorithm is fastest for random order? Why? 

//When I try to compile the code, it says "Error Opening File", so I couldn't compare them
//But according to BigO analysis, Algorithm2 and Algorithm3 faster than Algorithm1
