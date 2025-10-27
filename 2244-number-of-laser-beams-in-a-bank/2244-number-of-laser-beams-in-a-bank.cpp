class Solution {
public:
    long long countOnes(string& s){
        long long x=0;
        for(auto ele: s){
            if(ele=='1') x++;
        }
        return x;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<long long> v;
        for(auto ele: bank){
            long long x=countOnes(ele);
            if(x>0) v.push_back(x);
        }
        long long ans=0;
        for(int i=1;i<v.size();i++){
            ans+=(v[i]*v[i-1]);
        }
        return ans;
    }
};