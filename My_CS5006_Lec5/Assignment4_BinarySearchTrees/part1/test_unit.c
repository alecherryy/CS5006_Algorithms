/* TEST UNIT - This is a test file to ensure all methods of BST 
 * work corrently
 * */
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// import my_bst.h
#include "my_bst.h"

int main() {
    // create the tree
    bst_t * testBST = create_bst();

    // test bst_empty()
    printf("Test bst_empty()\n");
    printf("Expected: 1; actual: %d\n",bst_empty(testBST));

    // test bst_add()
    printf("Test bst_add()\n");
    printf("Add success, expected: 0; actual: %d\n",bst_add(testBST,20));
    printf("New root expected: 20; actual: %d\n",testBST->root->data);
    printf("Count: %d\n", testBST->count);
    bst_add(testBST,10);
    bst_add(testBST,15);
    bst_add(testBST,30);
    bst_add(testBST,25);
    bst_add(testBST,5);
    bst_add(testBST,35);
    printf("Count: %d\n", testBST->count);
    printf("Find 5. Expected: 1; actual: %d\n",find(testBST,5));
    printf("Find 35. Expected: 1; actual: %d\n",find(testBST,35));
    printf("Find 35. Expected: 1; actual: %d\n",find(testBST,20));
    printf("Find 12. Expected: 0; actual: %d\n",find(testBST,12));
    printf("Sum: %d\n",sum(testBST));
    bst_print(testBST,0);
    bst_print(testBST,-1);

    // free_bst(testBST);
    
    return 0;
}
