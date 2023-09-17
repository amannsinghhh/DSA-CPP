//17 september 2023
//Delete N nodes after M nodes of a linked list
//GFG

/*Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

*/


//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

// } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    int getlength(Node* head)
    {
        int l=0;
        while(head!=NULL)
        {
            l++;
            head=head->next;
        }
        return l;
    }
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        if(head==NULL||M>getlength(head)||N<=0||M<=0||N>getlength(head))
        {
            return;
        }
        Node* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            if(c==M)
            {
             int k=N;
             while(k--)
             {
                 if(temp->next!=NULL)
                 {
                    Node* t=temp->next;
                    temp->next=temp->next->next; 
                    t->next=NULL;
                    delete t;
                 }
             }
             c=0;   
            }
            temp=temp->next;
        }
    }
};



//{ Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}

// } Driver Code Ends
