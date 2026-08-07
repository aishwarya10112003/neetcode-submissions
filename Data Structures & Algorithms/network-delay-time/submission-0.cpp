class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0],v=times[i][1],t=times[i][2];
            adj[u].push_back({v,t});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto [d,u]=pq.top();pq.pop();
            if(dist[u]<d)continue;
            for(auto [child,w]:adj[u])
            {
                if(dist[child]>dist[u]+w)
                {
                    dist[child]=dist[u]+w;
                    pq.push({dist[child],child});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++)
        {
            if(dist[i]==INT_MAX)return -1;
            if(dist[i]>ans)ans=dist[i];
        }
        return ans;
    }
};
