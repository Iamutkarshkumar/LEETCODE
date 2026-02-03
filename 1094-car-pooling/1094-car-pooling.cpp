//Approach-2 (Using Difference Array Technique)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001,0);
        for(auto ele: trips){
            v[ele[1]]+=ele[0];
            v[ele[2]]-=ele[0];
        }
        int sum=0;
        for(int i=0;i<1001;i++){
            sum+=v[i];
            if(sum>capacity) return false;
        }
        return true;
    }
};
//Approach-1 (Using Line Sweep)
// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         map<int,int> mp;
//         for(auto ele: trips){
//             mp[ele[1]]+=ele[0];
//             mp[ele[2]]+=-1*ele[0];
//         }
//         int sum=0;
//         for(auto ele: mp){
//             sum+=ele.second;
//             if(sum>capacity) return false;
//         }
//         return true;
//     }
// };