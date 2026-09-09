class Solution {
public:
    int dp[101][101];
    bool solve(int i,int j,int k,string &s1,string &s2,string &s3)
    {
        if(k==s3.size())
        {
            return (i==s1.size() && j==s2.size());
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool res=false;
        if(i<s1.size() && s3[k]==s1[i])
        {
            res = solve(i+1,j,k+1,s1,s2,s3);
        }
        if(!res && j<s2.size() && s2[j]==s3[k])
        {
            res = solve(i,j+1,k+1,s1,s2,s3);
        }
        return dp[i][j]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        for(int i=0;i<=s1.size();i++)
        {
            for(int j=0;j<=s2.size();j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(0,0,0,s1,s2,s3);

    }
};
