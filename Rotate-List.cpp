// 17 september 2023
//61. Rotate List
//LC 61

/*Given the head of a linked list, rotate the list to the right by k places.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head==NULL||head->next==NULL)
    {
        return(head);
    }
    int size=0;
    struct ListNode* temp = head;
    while(temp)
    {
        temp = temp->next;
        size++;
    }
    k = k%size;    //k=size rotations will make the linked list same  
    for(int i=0;i<k;i++)
    {
        struct ListNode* temp = head;
        
        struct ListNode* prev = NULL;
        while(temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next=NULL;  //Second Last Node becomes NULL 
        temp->next = head; // Last node points towards head now
        head = temp; // last node is now the head 
    }
return(head);
}


};
