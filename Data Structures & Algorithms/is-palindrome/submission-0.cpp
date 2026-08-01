class Solution {
public:
    bool helper( string st)
    {
        int l=0 ,r=st.size()-1;
        while(l<=r)
        {
            if(st[l]!=st[r])return false;
            else 
            {
                l++;
                r--;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string st;
        for(int i=0;i<s.size();i++)
        {
            if(isalnum(s[i]))
            {
                st+=tolower(s[i]);
            }
        }
        return helper(st);
    
    }
};
