#include<bits/stdc++.h>
using namespace std;

// typedef struct Node{
// 	int data;
// 	Node *next;
// } Node;
class Node{
public: 
	int data;
	Node *next;
};


void insertBefore(Node **head, int new_data){
	Node *newNode = new Node();
	newNode->data = new_data;
	newNode->next = *head;
	*head = newNode;
}

void printData(Node *head){
	Node *curr_pointer = head;
	while(curr_pointer!=NULL){
		cout<< curr_pointer->data <<" ";
		curr_pointer = curr_pointer->next;
	}
	cout <<endl;
}

int main(int argc, char const *argv[])
{
	Node *head = NULL ;
	insertBefore(&head, 5);
	insertBefore(&head, 4);
	insertBefore(&head, 3);
	insertBefore(&head, 2);
	insertBefore(&head, 1);
	// printData(head);

	// int a[10];
	// a[0]=12;
	// a[1] =15;
	// cout << *a <<endl;
	// Node node;
	// node.data=6;
	// node.next=NULL;
	// nodes = &node;

	// cout << nodes[0].data <<endl;
	
	
	return 0;
}