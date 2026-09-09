class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<int>next(n+1,0),curr(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
          for(int prev=-1;prev<i;prev++)
          {
            int LIS = next[prev+1];
            if(prev==-1||nums[prev]<nums[i])
            {
                LIS = max(LIS,1+next[i+1]);
            }
            curr[prev+1]=LIS;
          }
          next = curr;
        }
        return next[0];
    }

};
