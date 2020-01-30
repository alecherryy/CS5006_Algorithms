// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

/* Swaps two numbers in an array
 * Input(s): 
 *          (1) the 'address of' an index into an array
 *          for position in an array
 * Output: Void.
 * */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


/* Sort function to order items in an array in ascending
 * order
 *
 * Name: sortIntegers
 * Input(s):
 *          (1) 'array' is a pointer to an integer address.
 *              is the start of some 'contiguous block of memory' 
 *              that we will sort.
 *          (2) 'size' indicates how big the array of data is
 * Output: Void. No value is returned, but 'array' should be modified
 * to store a sorted array of numbers.
 * */
void sortIntegers(int* array, unsigned int size) {
    int i, j, temp;

    for (i=1; i<size; i++) {
        temp = array[i];
        j = i-1;
        
        while (j>=0 && array[j]>temp) {
            // swap next next item with current item 
            swap(&array[j+1],&array[j]);
            j--;
        }
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
