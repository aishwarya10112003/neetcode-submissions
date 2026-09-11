class Solution {
public:
     int helper(int i,int j,vector<vector<int>>&dp,string &s,string &t)
     {
          int n = s.size();
          int m = t.size();
          if(i==n && j==m)return 0;
          if(i==n||j==m)
          {
            if(i==n)return m-j;
            else return n-i;
          }
          if(dp[i][j]!=-1)return dp[i][j];
          if(s[i]==t[j])
          {
            dp[i][j]=helper(i+1,j+1,dp,s,t);
          }
          else
          {
            dp[i][j]=
             1 + min({helper(i+1,j+1,dp,s,t),helper(i+1,j,dp,s,t),helper(i,j+1,dp,s,t)});
          }
          return dp[i][j];
     }
    int minDistance(string word, string word1) {
         int n =word.size();
         int m = word1.size();
          vector<vector<int>>dp(n,vector<int>(m,-1));
            return helper(0,0,dp,word,word1);
          
    }
};
