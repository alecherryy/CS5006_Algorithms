// =================== Support Code =================
// Binary Search Tree ( BST ).
//
//
//
// - Implement each of the functions to create a working BST.
// - Do not change any of the function declarations
//   - (i.e. bst_t* create_bst() should not have additional arguments)
// - You should not have any 'printf' statements in your BST functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYBST_H
#define MYBST_H
#include <stdlib.h> // Bring in standard functions like printf
#include <stdio.h> // Bring in malloc and free

/* Create a node data structure to store data within
 * the BST. In this case, we store 'integers'
 * */
typedef struct node {
    int data;
    struct node* rightChild;
    struct node* leftChild;
}node_t;

/* Create a BST data structure.
 * The BST holds a pointer to the root node in the 
 * BST called root.
 * */
typedef struct BST {
    int count;	    // count keeps track of how many items are in the BST.
    node_t* root;   // root points to the root node in our BST.
}bst_t;

/* Move node - This is a helper function for the bst_add() function. It takes 
 * a current node pointer and a new node, checks the value of the new node
 * against the curennt node and adds the new node to either the right or left.
 *
 * Input(s):
 *          (1) node_t* current, the current node
 *          (2) node_t* new_node, the new node
 * Returns void.
 * */
void move_node(node_t* current, node_t* new_node) {
    printf("Current %d vs New %d\n",current->data,new_node->data);
    // check if new node is smaller than current node
    if (new_node->data<current->data) {
        // check if current node right child is free
        if (current->rightChild==NULL) {
            current->rightChild = new_node;
        }
        else {
            // call move_node() on the current node right child
            move_node(current->rightChild,new_node);
        }
    }
    // if new node is greater or equal to current node
    else {
        if (current->leftChild==NULL) {
            current->leftChild = new_node;
        }
        else {
            // call move_node() on the current node left child
             move_node(current->leftChild,new_node);
        }
    }
}

/* Creates a BST - Returns a pointer to 
 * a newly created BST. The BST should be initialized with data on the heap and 
 * the BST fields should also be initialized to default values.
 * */
bst_t* create_bst() {
    bst_t* myBST;

    // Modify the body of this function as needed.
    myBST = (bst_t*)malloc(sizeof(bst_t));
    myBST->root = NULL;
    myBST->count = 0;

    if (myBST==NULL) {
        return NULL;
    }

    return myBST;
}

/* BST Empty - Check if the BST is empty
 *
 * Returns 1 if true (The BST is completely empty), otherwise returns 0 
 * if false (the BST has at least one element enqueued)
 * */
int bst_empty(bst_t* t) {
    
    // check if count equals 0, then BST is empty
    if (t->count==0) {
        return 1;
    }

    return 0;
}

/* BST Add - Adds a new node containing data in the 
 * correct place of the BST.
 * If the data is less then the current node we go right, 
 * otherwise we go left.
 *
 * Input(s):
 *          (1) a pointer to a BST
 *          (2) an integer representing the data of the new node
 * Returns -1 if the operation fails, otherwise returns 0.
 * */
int bst_add(bst_t* t, int item) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = item;
    new_node->rightChild = NULL;
    new_node->leftChild = NULL;
    
    if (t->count==0) {
        t->root = new_node;
        
        // increase BST count by 1
        t->count++;   
        return 0;
    } 
    else {
        move_node(t->root,new_node);

        // increase BST count by 1
        t->count++;

        return 0;
    } 
    return -1;
}

/* Ascending - Helper function for bst_print() method.
 *
 * Returns the nodes in ascending order (i.e. smallest to largest)
 * */
void ascending(node_t* node) {
    if (node==NULL) {
        return;
    }
    ascending(node->rightChild);
    printf("%d\n",node->data);
    ascending(node->leftChild);
}

/* Descending - Helper function for bst_print() method.
 *
 * Returns the nodes in descending order (i.e. smallest to largest)
 * */
void descending(node_t* node) {
    if (node==NULL) {
        return;
    }
    descending(node->leftChild);
    if (node!=NULL) {
        printf("%d\n", node->data);
    }
    descending(node->rightChild);
}

/* BST Print - Prints the tree in ascending order if order = 0, 
 * otherwise prints in descending order. 
 *
 * Input(s):
 *          (1) the BST
 *          (2) an intenger stating the order
 * For NULL tree it should print nothing. It should run in O(n) time.
 * */
void bst_print(bst_t* t, int order) {
    if (t==NULL) {
        return;
    }
    
    if (order==0) {
        printf("Print nodes in ascending order\n");
        ascending(t->root);
    }
    else {
        printf("Print nodes in descending order\n");
        descending(t->root);
    }
}

/* Sum Node - Helper function for sum() function
 *
 * Returns sum of the node
 * */
int sum_node(node_t* node) {

    // if node is NULL, return 0
    if (node==NULL) {
        return 0;
    } 

    // return current node data and call function left and right
    return (node->data + sum_node(node->leftChild) + sum_node(node->rightChild));
}

/* BST Sum - Sum together all the nodes in the tree
 *
 * Input(s):
 *          (1) the BST
 * Returns the sum of all the nodes in the tree. Exits the program 
 * for a NULL tree. It should run in O(n) time.
 * */
int sum(bst_t* t) {
    if (t==NULL) {
        return;
    }
    
    // return the sum
    return sum_node(t->root);
}

/* Compare Node - Helper function for find() function
 *
 * Returns void.
 * */
int compare_node(node_t* current, int value) {
    // if node is NULL, return 0
    if (current==NULL) {
        return 0;
    }
    // if current node data equals value, return 1
    if (current->data==value) {
        return 1;
    }
    // if value is less than node, go right
    else if (value<current->data) {
        compare_node(current->rightChild,value);
    }
    // if value is greater than node, go left
    else if (value>current->data) {
        compare_node(current->leftChild,value);
    }
}

/* Find - Find the given value inside the tree. 
 *
 * Input(s):
 *          (1) the tree
 *          (2) the value to look for
 * Returns 1 if value is found in the tree, 0 otherwise. For NULL tree 
 * it exists the program. Runs in O(log(n)) time.
 * */
int find(bst_t* t, int value){
    
    // if tree is NULL, return NULL 
    if (t==NULL) {
        return;
    }
    
    int found;
    // run helper function
    found = compare_node(t->root,value);

    return found;
}

/* BST Size - Queries the current size of the BST. A BST that has 
 * not been previously created will crash the program.
 *
 * Input(s):
 *          (1) the BST
 * Returns the size of the tree; returns -1 if the tree is NULL
 * */
unsigned int bst_size(bst_t* t) {
    if (t==NULL) {
        return -1;
    }        
    return t->count;
}

/* Free node - This is a helper function for the 
 * free_bst() function
 *
 * Input(s):
 *          (1) a pointer to a node
 * Returns void.
 * */
void free_node(node_t* node) {
    
    if (node!=NULL) {
        free_node(node->rightChild);
        free_node(node->leftChild);
        free(node); 
    }
}

/* Free BST - Removes a BST and ALL of its elements from memory.
 * This should be called before the proram terminates.
 *
 * Input(s):
 *          (1) the BST
 * Returns void
 * */
void free_bst(bst_t* t){
    
    free_node(t->root);
    free(t);   
}



#endif
