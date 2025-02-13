#define ll long long int
class Solution {
public:

    int minOperations(vector<int>& nums, int k) {
        ll n=nums.size();
        if(n==1) return 0;
        ll count=0;
        priority_queue<ll,vector<ll>,greater<ll>> pq(nums.begin(),nums.end());

        while(pq.size()>1 and pq.top()<k){
            ll x=pq.top();pq.pop();
            ll y=pq.top();pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            count++;
        }
        return count;
    }
};