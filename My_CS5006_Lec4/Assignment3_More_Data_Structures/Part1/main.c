// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.



// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    dll_t * dll = create_dll();
    
    printf("%d\n",dll);
    printf("Is empty? %d\n",dll_empty(dll));
    printf("Add to front? %d\n",dll_push_front(dll,8));
    printf("Add to front? %d\n",dll_push_front(dll,10));
    printf("New item's next: %d\n",dll->head->next->data);
    printf("Add to front? %d\n",dll_push_front(dll,3));
    printf("Add to front? %d\n",dll_push_front(dll,5));
    printf("Add to front? %d\n",dll_push_front(dll,2));
    printf("Total items: %d\n",dll->count);
    // printf("Pop front: %d\n",dll_pop_front(dll));
    //printf("Add to front? %d\n",dll_push_front(dll,7));
    //printf("Add to front? %d\n",dll_push_front(dll,6));
    //printf("Add to front? %d\n",dll_push_front(dll,1));
    //printf("Add to front? %d\n",dll_push_front(dll,5));
    // printf("Pop front: %d\n",dll_pop_front(dll));
    printf("Add to back? %d\n",dll_push_back(dll,11));
    printf("Add to back? %d\n",dll_push_back(dll,4));
    printf("New item's tail: %d\n",dll->tail->data);
    // printf("ITEM: %d\n",dll_get(dll,4));
    printf("ITEM: %d\n",dll_insert(dll,2,4));
    printf("Total items: %d\n",dll->count);
    printf("ITEM: %d\n",dll_remove(dll,1));
    printf("Head next: %d\n",dll->head->next->data);
    // printf("Total items: %d\n",dll->count);
    //printf("Insert a new item: %d\n",dll_insert(dll,4,9));
    // printf("After adding 12 to the list there are 12 items: %d\n",dll->count);
    free_dll(dll);
    // printf("%d\n",dll);
    // printf("Head next: %d\n",dll->head->next->data);
    //printf("Total items: %d\n",dll->count);
    return 0;
}
