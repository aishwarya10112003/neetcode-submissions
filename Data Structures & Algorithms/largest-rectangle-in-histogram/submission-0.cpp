class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse(n,n);
        vector<int>pse(n,-1);
        stack<int>st1,st2;

        for(int i=0;i<n;i++)
        {
            while(!st1.empty()&&heights[st1.top()]>heights[i])
            {
                int idx = st1.top();st1.pop();
                nse[idx]=i;
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
             while(!st2.empty()&&heights[st2.top()]>heights[i])
            {
                int idx = st2.top();st2.pop();
                pse[idx]=i;
            }
            st2.push(i);
        }
        int total=0,curr=0;
        for(int i=0;i<n;i++)
        {
            int width = nse[i]-pse[i]-1;
            curr = width*heights[i];
            total = max(total,curr);
        }
        return total;
    }   
};
