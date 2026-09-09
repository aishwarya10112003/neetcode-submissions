class Solution {
public:
   
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,-1);
        int n = s.size();
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int end = i+1;end<=n;end++)
            {
                if(wordSet.count(s.substr(i,end-i)) && dp[end])dp[i]=1;
            }
            if(dp[i]==-1)dp[i]=0;
        }
        return dp[0];
    }
};
