// class Solution {
// public:
//     string frequencySort(string s) {
//         string ans="";
//         unordered_map<char,int> mp;
//         for(auto ele: s) mp[ele]++;
//         priority_queue<pair<int,char>> pq;
//         for(auto ele: mp){
//             char first=ele.first;
//             int second=ele.second;
//             pq.push({second,first});
//         }
//         while(!pq.empty()){
//             auto ele =pq.top();
//             pq.pop();
//             int freq=ele.first;
//             char c=ele.second;
//             while(freq--) ans+=c;
//         }
//         return ans;
        
//     }
// };
// class Solution {
// public:
//     string frequencySort(string s) {
//         string ans="";
//         unordered_map<char,int> mp;
//         for(auto ele: s) mp[ele]++;
//         priority_queue<pair<int,char>> pq;
//         for(auto ele: mp){
//             char first=ele.first;
//             int second=ele.second;
//             pq.push({second,first});
//         }
//         while(!pq.empty()){
//             auto ele =pq.top();
//             pq.pop();
//             int freq=ele.first;
//             char c=ele.second;
//             while(freq--) ans+=c;
//         }
//         return ans;
        
//     }
// };
class Solution {
public:
    static bool cmp(pair<int,char> a , pair<int,char> b){
        return a.first>b.first;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto ele: s) mp[ele]++;
        vector<pair<int,char>> v;
        for(auto ele: mp){
            v.push_back({ele.second,ele.first});
        }
        sort(v.begin(),v.end(),cmp);
        string ans;
        for(auto ele: v){
            int c=ele.first;
            char x=ele.second;
            while(c--){
                ans.push_back(x);
            }
        }
        return ans;
    }
};