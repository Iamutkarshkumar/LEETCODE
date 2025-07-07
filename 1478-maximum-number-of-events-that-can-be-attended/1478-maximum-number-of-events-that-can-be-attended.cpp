class Solution {
public:
    // you can keep your cmp around, but we'll use it to sort by start here
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int maxEvents(vector<vector<int>>& events) {
        // 1) sort by start day
        sort(begin(events), end(events), cmp);

        // min‐heap of end‐days for all events "available" on the current day
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int ans = 0, day = 0, i = 0, n = events.size();
        while (i < n || !pq.empty()) {
            // if there are no pending events, jump to the next event's start
            if (pq.empty()) 
                day = max(day, events[i][0]);
            
            // push every event that starts on or before 'day'
            while (i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }
            
            // discard any events that already ended before today
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // attend the event that ends the earliest (if any)
            if (!pq.empty()) {
                pq.pop();
                ans++;
                day++;
            }
        }
        
        return ans;
    }
};
