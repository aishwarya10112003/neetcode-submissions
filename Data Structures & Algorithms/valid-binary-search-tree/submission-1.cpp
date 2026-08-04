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
    bool helper(TreeNode* root,int max,int min)
    {
        if(root==nullptr)return true;
        if(root->val>=max ||root->val<=min)return false;
        return helper(root->left,root->val,min)&&helper(root->right,max,root->val);
    }
    bool isValidBST(TreeNode* root) {
       return helper(root,INT_MAX,INT_MIN);
    }
};
