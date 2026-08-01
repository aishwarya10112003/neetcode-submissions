class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(256,0);
        if(s.size()<t.size())return "";
        for(int i=0;i<t.size();i++)
        {
            freq[t[i]]++;
        }
        int l=0,r=0;
        int minlen=INT_MAX,minIdx=-1;
        int need =t.size();
        while(r<s.size())
        {
           freq[s[r]]--;
           if(freq[s[r]]>=0)need--;
           while(need==0)
           {
               if(minlen>r-l+1)
               {
                  minIdx = l;
                  minlen = r-l+1;
               }
              freq[s[l]]++;
              if(freq[s[l]]>0)need++;
              l++;
           }
           r++;
        }
        return minIdx==-1?"":s.substr(minIdx,minlen);
    }
};
