class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        int count = 0;
        
        for (auto ele : nums) sum += ele;
        double half = sum / 2;

        priority_queue<double> pq(nums.begin(), nums.end()); // Max-heap
        
        while (sum > half) {
            double x = pq.top(); pq.pop();
            x /= 2;
            sum -= x;
            count++;
            pq.push(x);
        }
        return count;
    }
};
