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
     int helper(TreeNode*root,int &maxSum)
     {
         if(root==nullptr)return 0;
         int leftTree = max(0,helper(root->left,maxSum));
         int rightTree = max(0,helper(root->right,maxSum));
         maxSum = max(maxSum,leftTree+rightTree+root->val);
         return max(leftTree,rightTree)+root->val;
     }
    int maxPathSum(TreeNode* root) {
        int maxSum =-2000;
        int ans=helper(root,maxSum);
        return maxSum;
    }
};
