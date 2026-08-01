class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int num = nums[l]+nums[r];
            if(num<target)l++;
            else if(num>target)r--;
            else return {l+1,r+1};
        }
        return {l,r};
    }
};
