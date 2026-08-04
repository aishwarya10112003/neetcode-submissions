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
    vector<vector<int>> levelOrder(TreeNode* root) {
      
        queue<TreeNode*>que;
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int>arr;
            for(int i=0;i<size;i++)
            {
                TreeNode *curr= que.front();que.pop();
                arr.push_back(curr->val);
                if(curr->left!=nullptr)que.push(curr->left);
                if(curr->right!=nullptr)que.push(curr->right);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};
