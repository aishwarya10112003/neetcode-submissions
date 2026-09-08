class Solution {
public:
    int dp[11][10001];
    int helper(int i,vector<int>&coins,int amount)
    {
        int n =coins.size();
        if(amount==0)return 0;
        if(i==n)return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take =1e9;
        if(amount-coins[i]>=0)
        {
            take=1+helper(i,coins,amount-coins[i]);
        }
        int notTake = helper(i+1,coins,amount);
        return dp[i][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n =coins.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)dp[i][j]=-1;
        }
        int ans = helper(0,coins,amount);
        if(ans==1e9)return -1;
        return ans;
    }
};
