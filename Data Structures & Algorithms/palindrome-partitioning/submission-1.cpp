class Solution {
public:
    bool isPalindrome(string st,int l,int r)
    {
       while(l<=r)
       {
        if(st[l]==st[r])
        {
            l++;
            r--;
        }
        else return false;
       }
        return true;
    }

    vector<vector<string>>result;
    void backtrack(string s,vector<string>&curr,int start)
    {
        if(start==s.size())
        {
            result.push_back(curr);
            return;
        }
        for(int end=start;end<s.size();end++)
        {
            string str = s.substr(start,end-start+1);
            if(isPalindrome(s,start,end))
            {
                curr.push_back(str);
                backtrack(s,curr,end+1);
                curr.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
          vector<string>curr;
        backtrack(s,curr,0);
        return result;
    }
};
