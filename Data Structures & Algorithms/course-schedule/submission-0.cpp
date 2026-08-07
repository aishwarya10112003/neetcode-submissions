class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
         int n=edges.size();
         //khan's algorithm
         vector<vector<int>>adj(numCourses);
         vector<int>inDegree(numCourses,0);
         for(int i=0;i<n;i++)
         {
             int a =edges[i][0];
             int b =edges[i][1];
             adj[b].push_back(a);
             inDegree[a]++;
         }
         queue<int>que;
         for(int i=0;i<numCourses;i++)
         {
            if(inDegree[i]==0)que.push(i);
         }
        int visited=0;
         while(!que.empty())
         {
            int curr = que.front();que.pop();
            visited++;
            for(int nei : adj[curr])
            {
                inDegree[nei]--;
                if(inDegree[nei]==0)que.push(nei);
            }
         }
         return visited==numCourses?true:false;
      

    }
};
