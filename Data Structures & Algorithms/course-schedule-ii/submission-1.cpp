class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int>result;
        vector<vector<int>>adj(n);
        vector<int>inDegree(n,0);
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        queue<int>que;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)que.push(i);
        }
        while(!que.empty())
        {
            int curr=que.front();que.pop();
            result.push_back(curr);
            for(int nei:adj[curr])
            {
                inDegree[nei]--;
                if(inDegree[nei]==0)que.push(nei);
            }
        }
        if(result.size()!=n)return {};
        return result;
    }
};
