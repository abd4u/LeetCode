//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to insert a node in the middle of the linked list.
int countnode(Node* head)
{
    int count=-1;
    Node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
Node* insertInMiddle(Node* head, int x)
{
    if(head==NULL)
    return NULL;
    Node* prev=NULL;
    Node* temp=head;
    int len=countnode(head);
    int mid=len/2+1;
    int i=0;
    while(i<mid)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    Node* newnode=new Node(x);
    prev->next=newnode;
    newnode->next=temp;
    return head;
	// Code here
}