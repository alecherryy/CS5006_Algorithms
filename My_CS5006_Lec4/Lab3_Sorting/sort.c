// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============


/* Find the smallest integer from a range in a an array
 *
 * Input(s):
 *          (1) array - An array of integers
 *          (2) start - Where to start looking in an array
 *          (3) stop - End of where to search. Typically the 
 *              'size' of the array.
 *  Output: int. The index in an array of the minimum value 
 *  between a range [start,stop]
 *  */
int findMinimum(int* array, int start, int stop){
    int i, min;
    // set min as first item in range
    min = start;

    for (i=start+1; i<stop; i++) {
        // check if current item is smaller than min
        if (array[i]<array[min]) {
             // set new min to be current item
             min = i;
        }   
    }
    return min;
}


/* Swaps two numbers in an array 
 * Input: The 'address of' an index doubleo an array 
 * for positions in an array.
 * */
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


/* Sort function to order items in an array in ascending
 * order
 *
 * Name: sort
 * Input(s):
 *          (1) 'array' is a pointer to an integer address. This 
 *              is the start of some 'contiguous block of memory' 
 *              that we will sort.
 *          (2) 'size' indicates how big the array of data is
 * Output: Void. No value is returned, but 'array' should be modified 
 * to store a sorted array of numbers.
 * */
void sortIntegers(int* array, unsigned int size) {
    int i;
    
    // substract 1 from size since there are items left
    // to check 
    for (i=0; i<size-1; i++) {
        // set new min
        int new_min = findMinimum(array,i,size);
        
        // swap new min with current item
        swap(&array[new_min],&array[i]);
    }
}


/* Print an array
 *
 * Input(s): 
 *          (1) A pointer to an array
 *          (2) The size of the array
 * Output: Void.
 * */
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
