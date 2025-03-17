class Solution {
public:
    int countPairs(vector<int>& v, int t) {
        sort(v.begin(),v.end());
        int n=v.size();
        int l=0,h=n-1;
        int ans=0;
        while(l<h){
            if(v[l]+v[h]<t){
                ans+=h-l;
                l++;
            }
            else h--;
        }
        return ans;
    }
};