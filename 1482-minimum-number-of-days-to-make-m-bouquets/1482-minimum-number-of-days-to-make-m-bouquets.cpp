using ll=long long;
class Solution {
public:
    ll n;
    bool possible(ll mid,vector<int>& bloomDay, int m, int k){
        ll bouquetsCount=0;
        ll i=0;
        ll counter=0;
        while(i<bloomDay.size()){
            if(bloomDay[i]<=mid) counter++;
            else counter=0;
            if(counter==k){
                bouquetsCount++;
                counter=0;
            }
            i++;
        }
        return bouquetsCount>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        n=bloomDay.size();
        ll l=1;
        ll r=*max_element(begin(bloomDay),end(bloomDay));
        if((ll)m*k>n) return -1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(possible(mid,bloomDay,m,k)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};