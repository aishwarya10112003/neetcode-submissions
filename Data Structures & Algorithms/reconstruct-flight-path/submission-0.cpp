class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>>graph;
        for(auto & t :tickets)
        {
            graph[t[0]].push(t[1]);
        }
        vector<string>result;
        stack<string>stk;
        stk.push("JFK");
        while(!stk.empty())
        {
            string top = stk.top();
            if(graph[top].empty())
            {
                result.push_back(top);
                stk.pop();
            }
            else
            {
                stk.push(graph[top].top());
                graph[top].pop();
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
