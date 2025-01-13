class Solution {
public:
    int minimumLength(string s) {
        int ans=0;
        unordered_map<char,int> mp;
        for(auto ele: s) mp[ele]++;
        for(auto ele: mp){
            if(ele.second%2==0) ans+=2;
            else ans+=1;
        }
        return ans;
    }
};