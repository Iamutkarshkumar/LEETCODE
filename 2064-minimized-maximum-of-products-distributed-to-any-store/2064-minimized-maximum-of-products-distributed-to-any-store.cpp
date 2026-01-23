using ll=long long;
class Solution {
public:
    bool possible(int m,int n,vector<int>& quantities){
        ll stores=0;
        for(ll q:quantities){
            stores+=(q+m-1)/m;//ceil
            if(stores>n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        ll l=1,r=*max_element(begin(quantities),end(quantities));
        ll ans=0;
        while(l<=r){
            ll m=l+(r-l)/2;
            if(possible(m,n,quantities)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};