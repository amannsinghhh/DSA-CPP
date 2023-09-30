//Next greater node in linked list
//LC 1019

/*You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.*/



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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        while(head){
            ll.push_back(head->val);
            head=head->next;
        }
        stack<int>st;
        vector<int> ans(ll.size());
        for(int i=0;i<ll.size();i++){
            while(!st.empty() && ll[i]>ll[st.top()]){
                int kids=st.top();
                st.pop();
                ans[kids]=ll[i];
            }
            st.push(i);
        }
        return ans;
    }
};
