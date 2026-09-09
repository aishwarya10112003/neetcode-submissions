class Solution {
public:
    int dp[21][20001];
    int solve(int i,vector<int>&nums,int target)
    {
       
        if(i==nums.size())
        {
            if(target==0)return 1;
            else return 0;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int take = 0;
        if(target-nums[i]>=0)
        {
            take = solve(i+1,nums,target-nums[i]);
        }
        int notTake = solve(i+1,nums,target);
        return dp[i][target]=take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       
        int sum = accumulate(nums.begin(),nums.end(),0);
        target += sum;
    
        if(target<0 || target%2!=0)return 0;
        target/=2;
        
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(0,nums,target);

    }
};
