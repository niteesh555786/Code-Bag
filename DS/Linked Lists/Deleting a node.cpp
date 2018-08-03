#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node* push(struct Node **head,int data){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=*head;
	*head=newNode;
}

void printList(struct Node *node){
	while(node!=NULL){
		cout<<node->data<<" ";
		node=node->next;
	}
}

void deleteNode(struct Node **head_ref,int key){
	struct Node* temp=*head_ref,*prev;

	if(temp!=NULL && temp->data==key){
		*head_ref=temp->next;
		free(temp);
		return;
	}

	while(temp!=NULL && temp->data!=key){
		prev=temp;
		temp=temp->next;
	}

	if(temp==NULL)	return;

	prev->next=temp->next;
	free(temp);

}

int main(){
	struct Node *head=NULL;
	push(&head,7);
	push(&head,1);
	push(&head,3);
	push(&head,2);

	cout<<"Creating Linked List: ";
	printList(head);
	cout<<endl;
	cout<<"Linked list after deletion of 1:";
	deleteNode(&head,1);
	printList(head);


	return 0;
}