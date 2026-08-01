class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0,r=n-1;
        long long maxCap=0;
        while(l<r)
        {
          int left = heights[l];
          int right = heights[r];
          int height = min(left,right);
          long long cap = height*(r-l);
          maxCap = max(maxCap,cap);
          if(left<right)l++;
          else r--;
        }
        return maxCap;
    }
};
