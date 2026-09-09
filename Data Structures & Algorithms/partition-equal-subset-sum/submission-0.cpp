class Solution {
public:
    int dp[101][5001];
    int solve(int i,int target,vector<int>&nums)
    {
        int n = nums.size();
        if(target==0)return 1;
        if(i==n) return 0;
        if(dp[i][target]!=-1)return dp[i][target];
        int take =0;
        if(target-nums[i]>=0)
        {
            take = solve(i+1,target-nums[i],nums);
        }
        int notTake = solve(i+1,target,nums);
        return dp[i][target]= notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target%2!=0)return false;
        target /=2;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=target;j++)dp[i][j]=-1;
        }
        if(solve(0,target,nums))return true;
        else return false;
    }
};
