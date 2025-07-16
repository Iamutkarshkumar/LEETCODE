class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        for(auto ele: s) mp[ele]++;
        priority_queue<pair<int,char>> pq;
        for(auto ele: mp){
            char first=ele.first;
            int second=ele.second;
            pq.push({second,first});
        }
        while(!pq.empty()){
            auto ele =pq.top();
            pq.pop();
            int freq=ele.first;
            char c=ele.second;
            while(freq--) ans+=c;
        }
        return ans;
        
    }
};