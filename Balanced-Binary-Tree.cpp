//110. Balanced Binary Tree

/*Given a binary tree, determine if it is 
height-balanced
.*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftheight=maxDepth(root->left);
        int rightheight=maxDepth(root->right);
        int ans=max(leftheight,rightheight)+1;
        return ans;

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;

        }
        int leftheight=maxDepth(root->left);
        int rightheight=maxDepth(root->right);
        int diff=abs(leftheight-rightheight);
        bool ans1=(diff<=1);
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        if(ans1 &&left &&right){
            return true;
        }
        else
            return false;
    }
};
