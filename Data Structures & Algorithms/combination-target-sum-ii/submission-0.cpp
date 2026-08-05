class Solution {
public:
    vector<vector<int>>result;
     void backtrack(vector<int>&nums,int target,int i,vector<int>&curr)
     {
        if(target==0)
        {
            result.push_back(curr);
            return;
        }
        else if(i==nums.size()||target<0)return;

        target-=nums[i];
        curr.push_back(nums[i]);
        backtrack(nums,target,i+1,curr);
        target+=nums[i];
        curr.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1])i++;
        backtrack(nums,target,i+1,curr);

     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        backtrack(candidates,target,0,curr);
        return result;
    }
};
