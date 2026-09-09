class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &s1,string&s2)
    {
        int n = s1.size(),m=s2.size();
        if(i==n||j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])dp[i][j]=1+solve(i+1,j+1,s1,s2);
        else
        {
            int way1= solve(i+1,j,s1,s2);
            int way2=solve(i,j+1,s1,s2);
            dp[i][j]=max(way1,way2);
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
    int n =text1.size();
    int m =text2.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j] =-1;
        }
    }
    return solve(0,0,text1,text2);

 }
};
