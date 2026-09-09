class Solution {
public:
    int dp[5001][2];
    int solve(int i,int buy,vector<int>&prices)
    {
        int n=prices.size();
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy)
        {
            int take = -prices[i]+solve(i+1,0,prices);
            int notTake =solve(i+1,buy,prices);
            dp[i][buy]=max(take,notTake);
        }
        else
        {
           int sale = prices[i]+solve(i+2,1,prices);
           int notsale = solve(i+1,buy,prices);
            dp[i][buy]=max(sale,notsale);
        }
        return dp[i][buy];
        
    }
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<2;j++)
        {
            
            dp[i][j]=-1;
  
        }

      } 
      return solve(0,1,prices);


    }
};
