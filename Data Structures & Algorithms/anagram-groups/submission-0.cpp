class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mpp;
        for(string st :strs)
        {
            string temp = st;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(st);
        }
        for(auto & it:mpp)
        {
           ans.push_back(it.second);
        }
        return ans;
    }
};
