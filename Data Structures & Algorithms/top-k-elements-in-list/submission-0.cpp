class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        vector<vector<int>>freq(n+1);
        for(int num:nums)mpp[num]++;
        for(auto & it:mpp)
        {
            freq[it.second].push_back(it.first);
        }
        //now top k frequent elements 
        vector<int>ans;
        int count=0;
        for(int i=n;i>=1;i--)
        {
            for(int num:freq[i])
            {
                count++;
                ans.push_back(num);
                if(count==k)return ans;
            }
        }
        
    }
};
