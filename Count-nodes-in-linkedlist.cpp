//12 september 2023
//count number of nodes in linked list

/*Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.*/


class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        //Code here
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    
    }
};
