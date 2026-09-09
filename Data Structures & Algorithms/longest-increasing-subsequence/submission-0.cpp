class Solution {
public:
    int dp[1001][1001];
    int helper(int i,vector<int>&nums,int prev)
    {
        int n = nums.size();
        if(i==n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take =0;
        if(prev==-1 || nums[i]>nums[prev])
        {
            take =1+helper(i+1,nums,i);
        }
        int notTake = helper(i+1,nums,prev);
        return dp[i][prev+1]=max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }
        return helper(0,nums,-1);
    }

};
