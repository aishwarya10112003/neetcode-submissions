class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(int i=0;i<strs.size();i++){
            int size = strs[i].size();
            encoded += to_string(size)+'#'+strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
      int i =0;
      int n = s.size();
      vector<string>ans;
      while(i<n)
      {
         int j = s.find('#',i);
         int num = stoi(s.substr(i,j-i));
         string st = s.substr(j+1,num);
         ans.push_back(st);
         i = j+num+1;
      }
      return ans;
    
    }
};
