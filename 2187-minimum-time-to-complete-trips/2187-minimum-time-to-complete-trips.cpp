using ll=long long;
class Solution {
public:
    ll countTrips(vector<int>& time,ll m){
        ll ans=0;
        for(auto ele: time) ans+=m/ele;
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll n=time.size();
        ll maxEle=*max_element(begin(time),end(time));
        
        ll l=0,r=maxEle*totalTrips;

        while(l<=r){
            ll m = l+(r-l)/2;
            ll trips=countTrips(time,m);
            if(trips>=totalTrips) r=m-1;
            else l=m+1;
        }
        return l;
    }
};