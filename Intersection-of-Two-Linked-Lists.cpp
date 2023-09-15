// 15 september 2023
//160. Intersection of Two Linked Lists
//LC 160

/*Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a->next && b->next){
            if(a==b){
                return a; 
            }
            a=a->next;
            b=b->next;
        }
        if(a->next==0){
            //b is big find how big is b
            int blen=0;
            while(b->next){
                blen++;
                b=b->next;
            }
            while(blen--){
                headB=headB->next;
            }
        }
        if(b->next==0){
            //a is big find how big is b
            int alen=0;
            while(a->next){
                alen++;
                a=a->next;
            }
            while(alen--){
                headA=headA->next;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
