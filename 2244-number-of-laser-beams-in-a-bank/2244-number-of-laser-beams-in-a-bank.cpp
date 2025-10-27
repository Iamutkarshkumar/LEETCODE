class Solution {
public:
    int countOnes(string s){
        int x=0;
        for(auto ele: s){
            if(ele=='1') x++;
        }
        return x;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for(auto ele: bank){
            int x=countOnes(ele);
            if(x>0) v.push_back(x);
        }
        int ans=0;
        for(int i=1;i<v.size();i++){
            ans+=(v[i]*v[i-1]);
        }
        return ans;
    }
};