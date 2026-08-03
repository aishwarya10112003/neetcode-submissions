class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>>arr = mpp[key];
        int low=0,high=arr.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr[mid].second<=timestamp)
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans==-1?"":arr[ans].first;

    }
};
