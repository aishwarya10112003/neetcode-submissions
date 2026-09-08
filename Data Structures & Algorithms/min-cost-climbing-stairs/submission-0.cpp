class Solution {
public:
    int dp[101];
    int helper(int i,vector<int>&cost)
    {
        if(i==0||i==1)return 0;
        if(dp[i]!=-1)return dp[i];
      dp[i]= min(cost[i-1]+helper(i-1,cost),cost[i-2]+helper(i-2,cost));
        return dp[i];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        for(int i=0;i<=n;i++)dp[i]=-1;
        return helper(n,cost);
    }
};
