class Solution {
public:
    vector<string>result;
    void backtrack(int n ,string &curr,int close,int open)
    {
        if(close==n&&open==n){
            result.push_back(curr);
        }
        if(open<n)
        {
            curr.push_back('(');
            backtrack(n,curr,close,open+1);
            curr.pop_back();
        }
        if(open-close>0)
        {
            curr.push_back(')');
            backtrack(n,curr,close+1,open);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        backtrack(n,curr,0,0);
        return result;
    }
};
