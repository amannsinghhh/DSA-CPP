//113. Path Sum II

/*Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.*/



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

    void solve(TreeNode* root,int targetSum,int currsum,vector<int>path, vector<vector<int>>&ans){
        //basecase
        if(root==NULL){
            return;
        }
        //leaf node
        if(root->left==NULL &&root->right==NULL){
            path.push_back(root->val);
            currsum+=root->val;
            if(currsum==targetSum){
                ans.push_back(path);

            }
            return;
        }
        //include curr node
        path.push_back(root->val);
        currsum+=root->val;
        solve(root->left,targetSum,currsum,path,ans);
        solve(root->right,targetSum,currsum,path,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        int sum=0;
        vector<int> temp;
        solve(root,targetSum,sum,temp,ans);
        return ans;
    }
};
