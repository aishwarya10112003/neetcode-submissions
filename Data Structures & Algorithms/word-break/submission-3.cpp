class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.size();
        vector<int>dp(n+1,-1);
        dp[n]=1;
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(st.count(s.substr(i,j-i+1)) && dp[j+1])
                {
                    dp[i]=1;
                }
            }
           if(dp[i]==-1)dp[i]=0;
        }
        return dp[0];
    }
};
