class Solution {
public:
    vector<int> subarraySum(vector<int>& a, int t) {
        int l=0; long long s=0;
        for(int r=0;r<a.size();r++){
            s+=a[r];
            while(s>t && l<=r) s-=a[l++];
            if(s==t) return {l+1, r+1};
        }
        return {-1};
    }
};