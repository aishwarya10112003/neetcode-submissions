class Solution {
public:
    bool helper( vector<int>&piles,int k ,int h)
    {
        int  hours=0;
        for(int num :piles)
        {
            if(num%k==0)
            {
                hours+=num/k;
            }
            else 
            {
                hours+=(num/k)+1;
            }
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(),piles.end());
        int low = 1;
        int ans=high;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(helper(piles,mid,h))
            {
                ans =mid;
                high = mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
