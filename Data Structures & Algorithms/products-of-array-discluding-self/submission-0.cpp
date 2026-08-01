class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_product=1;
        int n=nums.size();
        vector<int>result(n,0);
        int count=0;
        for(int num:nums)
        {
            if(num==0)count++;
            if(count>1)return result;
            if(num!=0)total_product*=num;
        }
        
        for(int i=0;i<n;i++)
        {
            if(count==1)
            {
                if(nums[i]==0)result[i]=total_product;
            }
            else{
                result[i]=total_product/nums[i];
            }
        }
        return result;

    }
};
