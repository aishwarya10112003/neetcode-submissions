class Solution {
public:
    vector<int>parent,rank;
    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=find(parent[x]);
        }
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
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<edges.size();i++)
        {
            unite(edges[i][0],edges[i][1]);
        }
        set<int>st;
        for(int root:parent)
        {
            st.insert(find(root));
        }
        return st.size();
    }
};
