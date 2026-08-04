class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    KthLargest(int kth, vector<int>& nums) {
           k=kth;
          for (int x : nums) {
            pq.push(x);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        return pq.top();
    }
};
