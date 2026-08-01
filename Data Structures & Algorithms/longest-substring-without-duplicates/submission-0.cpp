class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mpp;
        int l=0,r=0;
        int n = s.size();
        int maxlen=0;
        while(r<n)
        {
            mpp[s[r]]++;
            while(mpp.size()<r-l+1)
            {
                mpp[s[l]]--;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
