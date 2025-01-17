class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> v(n);
        v[0]=start;
        for(int i=1;i<n;i++){
            v[i]=start+2*i;
        }
        int ans=0;
        for(auto ele: v) ans^=ele;
        return ans;
    }
};