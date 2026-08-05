class Solution {
public:
    vector<vector<int>>result;
    void backtrack(vector<int>&nums,int i,vector<int>&curr)
    {
        if(i==nums.size())
        {
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums,i+1,curr);
        while(i<nums.size()-1 && nums[i]==nums[i+1])i++;
        curr.pop_back();
        backtrack(nums,i+1,curr);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      vector<int>curr;
      backtrack(nums,0,curr);
      return result;

    }
};
