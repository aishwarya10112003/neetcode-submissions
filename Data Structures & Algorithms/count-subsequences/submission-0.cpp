class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&dp,string &s,string &t)
    {
         int n = s.size();
         int m=t.size();
         if(j==m)return 1;
         if(i==n)return 0;
         if(dp[i][j]!=-1)return dp[i][j];
         if(s[i]==t[j])
         {
            int notTake = helper(i+1,j,dp,s,t);
            int take = helper(i+1,j+1,dp,s,t);
            dp[i][j]=notTake+take;
         }
         else
         {
            dp[i][j]=helper(i+1,j,dp,s,t);
         }
         return dp[i][j];

    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();  
        if(n<m)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,dp,s,t);
    }
};
