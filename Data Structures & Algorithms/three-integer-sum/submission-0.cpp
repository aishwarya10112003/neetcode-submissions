class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue;
            int l=i+1,r=n-1;
            while(l<r)
            {
                int num = nums[i]+nums[l]+nums[r];
                if(num<0)l++;
                else if(num>0)r--;
                else 
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<n && nums[l]==nums[l-1])l++;
                    while(r>=0 && nums[r]==nums[r+1])r--;
                }
            }
        }
        return ans;
    }
};
