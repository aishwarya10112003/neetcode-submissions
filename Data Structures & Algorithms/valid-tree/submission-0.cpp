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
        parent[ry]=parent[rx];
        if(rank[rx]==rank[ry])rank[rx]++;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
       if(edges.size()!=n-1)return false;
       parent.resize(n);
       for(int i=0;i<n;i++)parent[i]=i;
       rank.resize(n,0);
       for(int i=0;i<edges.size();i++)
       {
         int x = edges[i][0];
         int y=edges[i][1];
         if(!unite(x,y))return false;
       }
       return true;
    }
};
  

