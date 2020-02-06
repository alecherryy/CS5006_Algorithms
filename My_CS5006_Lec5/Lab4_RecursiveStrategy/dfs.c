#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  struct TreeNode* left;
  struct TreeNode* right;
  char data;
}TreeNode_t;

/** Depth-first tree traversal - Traverses the tree depth 
 * first and prints each node in order or visit. Nodes
 * should be printed only once.
 * */
void dfs(TreeNode_t* start) {

    // print the current node
    printf("Char: %c\n",start->data); 
    
    // if there's a node on the left, traverse
    // the tree (i.e. go to the node on the left)
    if (start->left!=NULL) {
        dfs(start->left);
    }

    // if there's a node on the right, traverse
    // the tree (i.e. go to the node on the right)
    if (start->right!=NULL) {
        dfs(start->right);
    }
}

int main(){

  // Manually create a tree for this lab
  TreeNode_t* start = malloc(sizeof(TreeNode_t));
  TreeNode_t* a= malloc(sizeof(TreeNode_t));
  TreeNode_t* b= malloc(sizeof(TreeNode_t));
  TreeNode_t* c= malloc(sizeof(TreeNode_t));
  TreeNode_t* d= malloc(sizeof(TreeNode_t));
  TreeNode_t* e= malloc(sizeof(TreeNode_t));
  TreeNode_t* f= malloc(sizeof(TreeNode_t));
  TreeNode_t* g= malloc(sizeof(TreeNode_t));
  TreeNode_t* h= malloc(sizeof(TreeNode_t));

  // The root of our tree  
  // The root also has two 'branches' a and b.
  start->data = 's';
  start->left = a;
  start->right = b;
  
  a->data = 'a';
  a->left = c;
  a->right = d;
  
  b->data = 'b';
  b->left = e;
  b->right = f;
  
  c->data = 'c';
  c->left = g;
  c->right = h;

  // All of the 'leaves' in our tree
  d->data = 'd';
  d->left = NULL;
  d->right = NULL;   
  
  e->data = 'e';
  e->left = NULL;
  e->right = NULL;

  f->data = 'f';
  f->left = NULL;
  f->right = NULL;
  
  g->data='g';
  g->left = NULL;
  g->right = NULL;

  h->data = 'h';
  h->left = NULL;
  h->right = NULL;
  
  // Perform the dfs
  dfs(start);
  
  // Perform the dfs at a different spot)
  
  free(start);
  free(a);
  free(b);
  free(c);
  free(d);
  free(e);
  free(f);
  free(g);
  free(h);
  
  return 0;
}

