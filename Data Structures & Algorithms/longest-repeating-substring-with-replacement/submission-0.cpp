class Solution {
public:
    int characterReplacement(string s, int k) {
         vector<int>freq(26,0);
         int maxFreq=0,maxlen=0;
         int l=0,r=0;
         int n = s.size();
         while(r<n)
         {
            freq[s[r]-'A']++;
            maxFreq = max(freq[s[r]-'A'],maxFreq);
            while(((r-l+1)-maxFreq)>k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            maxlen = max(r-l+1,maxlen);
            r++;
         }
    return maxlen;

    }
};
