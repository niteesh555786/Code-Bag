#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;	
};

struct node* newNode(int data){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=temp->right=NULL;

	return temp;
}

int lisp(struct node* root){
	if(root==NULL)
		return 0;
	int size_excl=lisp(root->left)+lisp(root->right);
	int size_incl=1;
	if(root->left)
		size_incl+=lisp(root->left->left)+lisp(root->left->right);
	if(root->right)
		size_incl+=lisp(root->right->left)+lisp(root->right->right);

	return max(size_incl,size_excl);
}

int main(){
	struct node *root=newNode(20);
	root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    cout<<lisp(root);

	return 0;
}