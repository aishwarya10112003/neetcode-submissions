class Solution {
public:
    vector<vector<int>>result;
    void backtrack(vector<int>&nums,int i,vector<int>&curr,int &target)
    {
        if(target==0)
        {
            result.push_back(curr);
            return;
        }
        else if(target<0 || i==nums.size())return;

        target-=nums[i];
        curr.push_back(nums[i]);
        backtrack(nums,i,curr,target);
        target+=nums[i];
        curr.pop_back();
        backtrack(nums,i+1,curr,target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        backtrack(nums,0,curr,target);
        return result;
    }
};
