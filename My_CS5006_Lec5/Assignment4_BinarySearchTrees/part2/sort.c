// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

/** Merges two subarrays of arr[]. First subarray is arr[l..m] 
 * Second subarray is arr[m+1..r] 
 * 
 * Input(s):
 *          (1) array
 *          (2) integer l, lower bound
 *          (3) integer m, mid point
 *          (4) intger r, upper bound
 * Returns void.
 * */
void merge(int arr[], int l, int m, int r) {
    int i,j,k;
    int left, right;

    left = m-l+1;
    right = r-m;

    int left_side[left];
    int right_side[right];

    for (i=0; i<left; i++) {
        left_side[i] = arr[l+1];
    }
    
    for (j=0; j<right; j++) {
        right_side[j] = arr[m+1+j];
    }

    i = 0;
    j = 0;
    k = 0;

    while (i<left && j<right) {
        
        if (left_side[i]<=right_side[j]) {
            arr[k] = left_side[i];
            i++;
        }
        else {
            arr[k] = right_side[j];
            j++;
        }
        k++;
    }

    while (i<left) {
        arr[k] = left_side[i];
        i++;
        k++;
    }

    while (j<right) {
        arr[k] = right_side[j];
        j++;
        k++;
    }
}

/** Sort function.
 *
 * Input(s):
 *          (1) 'array' is a pointer to an integer address. 
 *          This is the start of some 'contiguous block of memory' that we will sort.
 *          (2) 'size' tells us how big the array of data is we are sorting.
 *          Output: No value is returned, but 'array' should be modified
 *          to store a sorted array of numbers.
 * Returns void.
 * */
void sortIntegers(int* array, unsigned int size){
    int l,r;

    l = 1;
    r = size+1;

    if (l<r) {
        int m = l+(r-1)/2;

        sortIntegers(array,m-l);
        sortIntegers(array,r-m+1);

        merge(array,l,m,r);
    }
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);
  
  return 0;
}
