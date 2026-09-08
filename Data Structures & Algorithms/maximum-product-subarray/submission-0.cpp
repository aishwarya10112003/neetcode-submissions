class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long globalMax=nums[0];
        long long currmax=nums[0],currmin=nums[0];
        int n =nums.size();
        for(int i=1;i<n;i++)
        {
            long long temp =currmax;
            currmax = max({currmax*nums[i],(long long)nums[i],currmin*nums[i]});
            currmin = min({temp*nums[i],(long long) nums[i],currmin*nums[i]});
            globalMax = max({globalMax,currmin,currmax});
        }
        return globalMax;
    }
};
