class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        vector<int>ans;
        int r=0;
        int n = nums.size();
        while(r<n)
        {
            while(!dq.empty() && dq.front().second<=r-k) dq.pop_front();
            
            while(!dq.empty() && dq.back().first<=nums[r]) dq.pop_back();

            dq.push_back({nums[r],r});

            if(r>=k-1)
            {
                ans.push_back(dq.front().first);
            }
            r++;
        }
        return ans;
    }
};
