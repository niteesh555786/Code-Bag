#include <bits/stdc++.h>

/* A binary tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
/* Utility function to create a new Binary Tree node */
struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* constructUtilTree(int pre[],int *index_ptr,char preLN[],int size){
	int index=*index_ptr;

	if(index==size)
		return NULL;

	struct node *temp=newNode(pre[index]);
	(*index_ptr)++;

	if(preLN[index]=='N'){
		temp->left=constructUtilTree(pre,index_ptr,preLN,size);
		temp->right=constructUtilTree(pre,index_ptr,preLN,size);
	}

	return temp;
}

struct node* constructTree(int pre[],char preLN[],int size){
	int index=0;
	return constructUtilTree(pre,&index,preLN,size);
}

/* This function is used only for testing */
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder (node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder (node->right);
}
 
/* Driver function to test above functions */
int main()
{
    struct node *root = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 */
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    // construct the above tree
    root = constructTree (pre, preLN, n);
 
    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);
 
    return 0;
}
