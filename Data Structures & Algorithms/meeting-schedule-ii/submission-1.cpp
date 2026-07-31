/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
         priority_queue<int,vector<int>,greater<int>>pq;
         int n = intervals.size();
         sort(intervals.begin(),intervals.end(),[](const Interval& a ,const Interval& b)
         {
             return a.start < b.start;
         });
         for(int i=0;i<n;i++)
         {
           if(!pq.empty() && pq.top()<=intervals[i].start) pq.pop();
           pq.push(intervals[i].end);
 
         }
         return pq.size();
    }
};
