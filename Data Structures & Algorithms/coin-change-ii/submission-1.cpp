class Solution {
public:
    int dp[101][5001];
    int solve(int i,vector<int>&coins,int amount)
    {
        int n = coins.size();
        if(amount==0)return 1;
        if(i==n)return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take =0;
        if(amount-coins[i]>=0)
        {
            take = solve(i,coins,amount-coins[i]);
        }
        int notTake = solve(i+1,coins,amount);
        return dp[i][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
                dp[i][j]=-1;
        }
       return  solve(0,coins,amount);
    }
};
