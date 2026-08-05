class Solution {
public:
    vector<vector<int>>result;
    void backtrack(vector<int>&nums,vector<bool>&used,vector<int>&curr)
    {
         int n=nums.size();
         if(curr.size()==n){
            result.push_back(curr);
            return;
         }
    
        for(int i=0;i<n;i++)
        {
            if(!used[i])
            {
                used[i]=true;
                curr.push_back(nums[i]);
                backtrack(nums,used,curr);
                used[i]=false;
                curr.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<int>curr;
         vector<bool>used(nums.size());
         backtrack(nums,used,curr);
         return result;
    }
};
