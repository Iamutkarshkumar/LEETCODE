class Solution {
public:
    int countSetBits(int n){
        int ans=0;
        while(n>0){
            if(n&1==1) ans++;
            n>>=1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countSetBits(i));
        }
        return ans;
    }
};