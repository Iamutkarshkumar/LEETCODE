class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> v;
        int n=weights.size();
        for(int i=0;i<n-1;i++) v.push_back(weights[i]+weights[i+1]);
        sort(v.begin(),v.end());
        long long mnele=0,mxele=0;
        int l=v.size();
        for(int i=0;i<k-1;i++) mnele+=v[i];
        for(int i=l-1;i>l-k;i--) mxele+=v[i];
        return mxele-mnele;
    }
};