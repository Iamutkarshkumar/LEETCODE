using ll=long long;
class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> mp;
        while(n){
            int d=n%10;
            mp[d]++;
            n/=10;
        }
        ll ans=0;
        for(auto ele: mp){
            ans+=ele.first*ele.second;
        }
        return ans;
    }
};