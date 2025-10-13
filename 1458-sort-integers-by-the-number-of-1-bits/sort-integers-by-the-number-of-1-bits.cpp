class Solution {
public:
    static bool cmp(int a,int b){
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);
        if(c1 == c2) return a < b; 
        return c1 < c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), cmp);
        return arr;
    }
};
// using p=pair<int,int>;
// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
//         priority_queue<p,vector<p>,greater<p>> pq;
//         vector<int> ans;
//         for(auto ele: arr) pq.push({__builtin_popcount(ele),ele});
//         while(not pq.empty()){
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         return ans;
//     }
// };