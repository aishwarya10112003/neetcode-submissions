class Solution {
public:
    vector<int>dp;
    bool solve(string s,unordered_set<string>wordSet,int i)
    {
        int n = s.size();
        if(i==n)return true;
        if(dp[i]!=-1)return dp[i];

        for(int end=i+1;end<=n;end++)
        {
            if(wordSet.count(s.substr(i,end-i)) && solve(s,wordSet,end))
            {
               return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        dp.resize(s.size(),-1);
        return solve(s,wordSet,0);
    }
};
