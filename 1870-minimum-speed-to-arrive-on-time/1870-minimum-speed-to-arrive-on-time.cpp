using ll = long long;
class Solution {
public:
    double calcTime(vector<int>& dist,ll speed){
        double time=0;
        int n=dist.size();
        for(int i=0;i<n;i++) {
            if(i==n-1) time+=(1.0*dist[i])/(speed);
            else time+=ceil((1.0*dist[i])/(speed));
        }
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        //time = dist/speed
        ll l= 1,h=1e7;
        ll ans=-1;
        while(l<=h){
            ll m =l+(h-l)/2;
            double time = calcTime(dist,m);
            if(time<=hour){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};