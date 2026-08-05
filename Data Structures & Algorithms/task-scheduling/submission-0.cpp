class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
           priority_queue<int>pq;
           unordered_map<int,int>mpp;
           for(int i=0;i<tasks.size();i++)
           {
              mpp[tasks[i]]++;                            
           }
           for(auto it:mpp)
           {
             pq.push(it.second);
           }
           int currTime=0;
           queue<pair<int,int>>que;
           while(!pq.empty() || !que.empty())
           {
             currTime++;
             if(!que.empty())
             {
                auto [time,freq]=que.front();
                if(time==currTime)
                {
                    que.pop();
                    pq.push(freq);
                }
             }
             if(!pq.empty())
             {
                int freq=pq.top();pq.pop();
                freq--;
                if(freq!=0)
                {
                    que.push({currTime+n+1,freq});
                }
             }
           }
           return currTime;
    }
};
