//17 september 2023
//2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
//LC 2058

/*A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={-1,-1};
        ListNode* prev=head;
        if(prev==NULL){
            return ans;
        }
        ListNode* curr=head->next;
        if(curr==NULL){
            return ans;
        }
        ListNode* next=head->next->next;
        if(next==NULL){
            return ans;
        }
        int firstcritical=-1;
        int lastcritical=-1;
        int mini=INT_MAX;
        int i=1;
        while(next!=NULL){
            bool isCP=((curr->val>prev->val && curr->val>next->val)||(curr->val<prev->val && curr->val<next->val)) ? true : false;
            if(isCP &&firstcritical==-1){
                firstcritical=i;
                lastcritical=i;
            }
            else if(isCP){
                mini=min(mini,i-lastcritical);
                lastcritical=i;
            }
            ++i;
            prev=prev->next;
            curr=curr->next;
            next=next->next;

        }
        if(lastcritical==firstcritical){ //only one cp is found
            return ans;
        }
        else{
            ans[0]=mini;
            ans[1]=lastcritical-firstcritical;
        }
        return ans;
    }
};
