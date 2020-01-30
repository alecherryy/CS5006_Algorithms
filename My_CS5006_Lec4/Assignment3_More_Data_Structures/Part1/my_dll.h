// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#define MYDLL_H
#define MYDLL_H
#include <stdlib.h> // Bring in standard functions like printf
#include <stdio.h> // Bring in malloc and free

/**
 * Create a node data strcuture to store
 * data within our DLL. In our case, we will store
 * 'integers'
 * */
typedef struct node {
	int data;
	struct node* next;
  	struct node* previous;
}node_t;

/**
 * Create a DLL data structure - Our DLL holds a pointer
 * to the first node in our DLL called head and a 
 * pointer to the last node in our DLL called tail
 * */
typedef struct DLL { 
	int count;	// count keeps track of how many items are in the DLL.
	node_t* head;	// head points to the first node in our DLL.
        node_t* tail;  // tail points to the last node in our DLL.
}dll_t;

/**
 * Create a DLL - The DLL should be initialized with data 
 * on the heap. The fields should be initialized to 
 * default values
 *
 * Return: a pointer to the newly created DLL.
 * */
dll_t* create_dll() {
    // Modify the body of this function as needed.
    dll_t* myDLL;
    
    myDLL = (dll_t*)malloc(sizeof(dll_t));
    myDLL->count = 0;
    myDLL->head = NULL;
    myDLL->tail = NULL;
    
    if (myDLL==NULL) {
        return NULL;
    }
    return myDLL;
}

/** DLL Empty - Check if the DLL is empty
 *
 * Input(s):    a double linked list
 * Returns 1 if true, 0 is false
 * */
int dll_empty(dll_t* l){
    
    if (l->count<1) {
        return 1;
    }
    return 0;
}

/* Push Front - Push a new item to the front of the DLL 
 * (before the first node in the list).
 *
 * Input(s):
 *          (1) the DLL
 *          (2) the item to be pushed (int)
 * Returns -1 if the operation fails (and if the DLL is NULL),
 * otherwise returns 1 on success.
 * */
int dll_push_front(dll_t* l, int item) {

    node_t* new_item = (node_t*)malloc(sizeof(node_t));
    new_item->data = item;
    
    new_item->next = l->head; 
    new_item->previous = NULL;

    if (l->head!=NULL) {
        l->head->previous = new_item;
    }
    l->head = new_item;
     
    // increase list count by 1
    l->count++;

    if (l==NULL) {
        return -1;
    }
    
    return 1;
}

/* Push Back - Push a new item to the back of the DLL 
 * (after the last node in the list).
 *
 * Input(s):
 *          (1) the DLL
 *          (2) the item to be pushed (int)
 * Returns -1 if the operation fails (and if the DLL is NULL),
 * otherwise returns 1 on success.
 * */
int dll_push_back(dll_t* l, int item) {
    node_t* temp;
    temp = l->head;

    node_t* new_item = (node_t*)malloc(sizeof(node_t));
    new_item->data = item;

    // make new item the tail of the list
    new_item->next = NULL;
    
    // if the list is empty, set the new node as the head
    if (l->head==NULL) {
        new_item->previous = NULL;
        l->head = new_item;
        
        return 1;
    }
    
    // traverse the list until reaching the end
    while (temp->next!=NULL) {
        temp = temp->next;
    }

    // set next of the last item to be the new node
    temp->next = new_item;
    // set the previous of the new node to the be what was
    // the last item
    new_item->previous = temp;
    // set the new node to be the tail
    l->tail = new_item;

    // increase list count by 1
    l->count++;

    if (l==NULL) {
        return -1;
    }
    
    return 1;
}

/* Pop Front - Pop the first item of the DLL 
 *
 * Input(s):
 *          (1) the DLL
 * Returns -1 if the operation fails (and if the DLL is NULL),
 * otherwise returns the element that was removed
 * */
int dll_pop_front(dll_t* t) {
    node_t* temp;
    int top;
    temp = t->head;
    top = t->head->data;

    t->head = t->head->next;
    free(temp);
    // decrease list count by 1
    t->count--;
    
    if (t==NULL) {
        return -1;
    }

    return top;
}

/* Pop Back - Pop the last item of the DLL
 *
 * Input(s):
 *          (1) the DLL
 * Returns -1 if the operation fails (and if the DLL is NULL),
 * otherwise returns the element that was removed
 * */
int dll_pop_back(dll_t* t) {
    node_t* temp;
    int back;
    temp = t->tail;
    back = t->tail->data;

    t->tail = t->tail->previous;
    free(temp);

    // decrease list count by 1
    t->count--;

    if (t==NULL) {
        return -1;
    }

    return back;
}

/* Insert - Inserts a new node before the node at the 
 * specified position. Assumption that position starts at 0
 * Input(s):
 *          (1) the DLL
 *          (2) the position of the item in the list
 *          (3) the new item
 * being the first item. Total lenght of the list is dll->count - 1
 * Returns -1 if the operation fails (and if the DLL is NULL), otherwise returns 1 on success.
 * */
int dll_insert(dll_t* l, int pos, int item) {
    node_t* current_item;
    int i;

    node_t* new_item = (node_t*)malloc(sizeof(node_t));
    new_item->data = item;
    
    // if list is null or pos is out of range
    if (l==NULL || pos>l->count-1) {
        return -1;
    }

    // if new item is head, execute push front
    if (pos==0) {
        dll_push_front(l,item);
    }
    else if (pos==l->count-1) {
        current_item = l->tail->previous;
        
        l->tail->previous = new_item;
        new_item->previous = current_item;

        // increase list count by 1
        l->count++;
    }
    else {
        node_t* previous_item;
        
        // the item at the position
        current_item = l->head->next;
        // the item before the current pos
        previous_item = l->head;

        for (i=1; i<l->count-1; i++) {
            
            // if the current item is at pos
            if (pos==i) {
                // set previous item to point to new one
                previous_item->next = new_item;
                // set current item to point to new one
                current_item->previous = new_item;
                // set pointer for new item
                new_item->next = current_item;
                new_item->previous = previous_item;
                
                // increase list count by 1
                l->count++;
            }
            
            // shift current and previous item by one
            previous_item = previous_item->next;
            current_item = current_item->next;
        }
    }

    return 1;
}

/* Get - Returns the item at position pos starting at 0 
 * (0 being the first item)
 *
 * Input(s):
 *          (1) the DLL
 *          (2) an int pos indicating the position of the item in
 *              the list
 * Returns the item at position if the operation succeed, -1 if the 
 * operation fails (and if the DLL is NULL).
 * */
int dll_get(dll_t* l, int pos) {
    node_t* temp;
    int i;

    temp = l->head;
    
    // if list is null or pos is out of range
    if (l==NULL || pos>l->count-1) {
        return -1;
    }    
    // if pos is 0, return the first item in the list
    if (pos==0) {
        return l->head->data;
    }      
   // if pos is the length of the list - 1, return the last item 
   // in the list 
    else if (pos==l->count-1) {
        return l->tail->data;
    }
    else {
        // iterate through the list and return the item when 
        // the index matches the position
        for (i=1; i<l->count-1; i++) {
            temp = temp->next;

            if (pos==i) {
                return temp->data;
            }           
        }
    }

    return 1; 
}

/* Remove - Removes the item at position pos starting at 0 
 * (0 being the first item)
 *
 * Input(s):
 *          (1) the DLL
 *          (2) an int pos indicating the position of the item in
 *          the list
 * Returns a -1 if the operation fails (and if the DLL is NULL). 
 * */
int dll_remove(dll_t* l, int pos){
    int i;
    
    // if list is null or pos is out of range
    if (l==NULL || pos>l->count-1) {
        return -1;
    }

    // if item is head, execute pop front
    if (pos==0) {
        dll_pop_front(l);
    }
    // if item is tail, execute pop back 
    else if (pos==l->count-1) {
        dll_pop_back(l);
    }
    else {
        node_t* current_item;
        node_t* previous_item;
        node_t* next_item;

        // the item at the position 
        current_item = l->head->next;
        // the item before the current pos
        previous_item = l->head;
        // the item after the current pos
        next_item = current_item->next;
        for (i=1; i<l->count-1; i++) {
            
            if (pos==i) {
                previous_item->next = next_item;
                next_item->previous = previous_item;
                free(current_item);

                // decrease list count by 1
                l->count--;
            }
            
            // shift current, next and previous item by one
            previous_item = previous_item->next;
            current_item = current_item->next;
            next_item = next_item->next;
        }

        return 0;       
    } 
}

/* Size - Queries the current size of a DLL
 * Returns -1 if the DLL is NULL.
 * */
unsigned int dll_size(dll_t* t){
    if (t==NULL) {
        return -1;
    }
    return t->count;
}

/* Free DLL - Removes a DLL and ALL of its elements from memory.
 * */
void free_dll(dll_t* t) {
    node_t* current;
    current = t->head;
    
    while (current!=NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }

    free(t);
}

#endif
