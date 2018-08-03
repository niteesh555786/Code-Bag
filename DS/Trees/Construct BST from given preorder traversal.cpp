#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

struct node* newNode(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=temp->right=NULL;

	return temp;
}
// A utility function to print inorder traversal of a Binary Tree
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

struct node* constructUtilTree(int pre[],int *preIndex,int key,int min,int max,int size){
	if(*preIndex >= size)
		return NULL;

	struct node *root=NULL;

	if(key>min && key<max){
		root=newNode(key);
		*preIndex=*preIndex+1;

		if(*preIndex< size){
			root->left=constructUtilTree(pre,preIndex,pre[*preIndex],min,key,size);
			root->right=constructUtilTree(pre,preIndex,pre[*preIndex],key,max,size);
		}
	}

	return root;
}

struct node* constructTree(int pre[],int size){
	int preIndex=0;

	return constructUtilTree(pre,&preIndex,pre[0],INT_MIN,INT_MAX,size);
}

int main(){
	int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node* root=constructTree(pre,size);
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
    
	return 0;
}