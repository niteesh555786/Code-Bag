#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node *findLCA(Node *root,int n1,int n2){
	if(root==NULL)
		return root;
	if(root->key==n1 || root->key==n2)
		return root;

	Node *left_lca=findLCA(root->left,n1,n2);
	Node *right_lca=findLCA(root->right,n1,n2);

	if(left_lca && right_lca)
		return root;

	return (left_lca!=NULL)? left_lca:right_lca;

}

int findLevel(Node *root,int n,int level){
	if(root==NULL)
		return -1;
	if(root->key==n)
		return level;
	int left=findLevel(root->left,n,level+1);
	if(left==-1)
		return findLevel(root->right,n,level+1);
	return left;
}

int findDistance(Node *root,int n1,int n2){
	Node *lca=findLCA(root,n1,n2);

	int d1=findLevel(lca,n1,0);
	int d2=findLevel(lca,n2,0);

	return (d1+d2);
}

int main(){
 // Let us create binary tree given in the
    // above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}