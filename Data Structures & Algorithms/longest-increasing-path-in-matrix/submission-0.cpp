class Solution {
public:
   int dfs(int row,int col,int prev,vector<vector<int>>&matrix,vector<vector<int>>&dp)
   {
     int n =matrix.size();
     int m = matrix[0].size();
     if(row<0 || row>=n||col>=m||col<0||matrix[row][col]<=prev)return 0;
     if(dp[row][col]!=-1)return dp[row][col];
     int res =1;
     int dr[]={1,-1,0,0};
     int dc[]={0,0,1,-1};
     for(int i=0;i<4;i++)
     {
        res = max(res,1+dfs(row+dr[i],col+dc[i],matrix[row][col],matrix,dp));
     }
     dp[row][col]=res;
     return dp[row][col];
   }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int m =matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int LIS=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
             LIS = max(LIS,dfs(i,j,INT_MIN,matrix,dp));
            }
        }
        return LIS;
    }
};
