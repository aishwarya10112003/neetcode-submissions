class Solution {
public:
    vector<int>parent,rank;
    int find(int x)
    {
        if(parent[x]!=x)parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unite(int x,int y)
    {
        int rx=find(x),ry=find(y);
        if(rx==ry)return false;
        if(rank[rx]<rank[ry])swap(rx,ry);
        parent[ry]=rx;
        if(rank[rx]==rank[ry])rank[rx]++;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=1;i<n+1;i++) parent[i]=i;
        rank.resize(n+1,0);
        vector<int>rdnt;
        for(int i=0;i<n;i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            if(!unite(a,b))
            {
               rdnt={a,b};
            }
        }
        return rdnt;
    }
};
