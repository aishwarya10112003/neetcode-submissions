class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>result(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&temp[st.top()]<temp[i])
            {
                int index = st.top();st.pop();
                result[index]=i-index;
            }
            st.push(i);
        }
        return result;
    }
};
