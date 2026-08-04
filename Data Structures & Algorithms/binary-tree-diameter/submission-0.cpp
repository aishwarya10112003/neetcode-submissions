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
    int helper(TreeNode* root,int &diameter)
    {
        if(root==NULL)return 0;
        int left_h = helper(root->left,diameter);
        int right_h = helper(root->right,diameter);
        diameter = max(diameter,left_h+right_h);
        return max(left_h,right_h)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        int height = helper(root,diameter);
        return diameter;
    }
};
