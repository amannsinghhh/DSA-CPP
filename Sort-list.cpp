//17 september 2023
// 148. Sort List
// LC 148

/*Given the head of a linked list, return the list after sorting it in ascending order.*/


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

    ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merged(ListNode* left, ListNode* right) {
        if(left==0) return right;
        if(right==0) return left;
        ListNode* newNode=new ListNode(-1);
        ListNode* mptr=newNode;
        while(left && right){
            if(left->val<=right->val){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else{
                mptr->next=right;
                mptr=right;
                right=right->next;
            }

        }
        if(left){
            mptr->next=left;
            
        }
        if(right){
            mptr->next=right;
            
        }
        return newNode->next;
    }
    ListNode* sortList(ListNode* head) {
       if(head==0 || head->next==0){
           return head;
       } 
       //break ll in 2 half using mid
       ListNode* mid=findmid(head);
       ListNode* left= head;
       ListNode* right=mid->next;
       mid->next=NULL;
       //sort Recursion
       left=sortList(left);
       right=sortList(right);

       //merge both

       ListNode* merge=merged(left,right);
       return merge;

    }
};
