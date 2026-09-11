class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&dp,vector<int>&arr)
    {
        if(j-i<=1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int coins=0;
        for(int k=i+1;k<j;k++)
        {
            coins=max(coins,helper(i,k,dp,arr)+helper(k,j,dp,arr)+arr[i]*arr[k]*arr[j]);
        }
        return dp[i][j]=coins;
    }
    int maxCoins(vector<int>& nums) {
        int n =nums.size();
        vector<int>arr(n+2);
        arr[0]=1;
        arr[n+1]=1;
        for(int i=1;i<=n;i++)arr[i]=nums[i-1];
       vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return helper(0,n+1,dp,arr);
    }
};
