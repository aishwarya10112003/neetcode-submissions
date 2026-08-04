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
   
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>que;
        vector<int>ans;
        if(root==nullptr)return ans;
        que.push(root);
        while(!que.empty())
        {
            int size =que.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr = que.front();que.pop();
                if(curr->left!=nullptr)que.push(curr->left);
                if(curr->right!=nullptr)que.push(curr->right);
                if(i==size-1)ans.push_back(curr->val);
            }
        }
        return ans;
    }
};
