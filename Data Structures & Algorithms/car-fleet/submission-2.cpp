class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
          vector<pair<int,double>>arr;
          int n =position.size();
          for(int i=0;i<n;i++)
          {
            double time = (double)(target-position[i])/speed[i];
            arr.push_back({position[i],time});
          }
          sort(arr.begin(),arr.end());
          stack<double>st;
          for(int i=n-1;i>=0;i--)
          {
           if(st.empty()||st.top()<arr[i].second)st.push(arr[i].second);

          }
          return st.size();

    }
};
