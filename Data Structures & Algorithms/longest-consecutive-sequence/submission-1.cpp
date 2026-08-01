class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int curr=1,maxLen=1;
        int n = nums.size();
        if(n==0)return 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)curr++;
            else if(nums[i]==nums[i-1])continue;
            else curr=1;
            maxLen = max(curr,maxLen);
        }
        return maxLen;
    }
};
