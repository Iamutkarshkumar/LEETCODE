class Solution {
public:
    int n;
    bool help(vector<int>& v,double m,int k){
        for(int i=1;i<n;i++){
            int x=ceil((double)(v[i]-v[i-1])/m)-1;
            k-=x;
            if(k<0) return false;
        }
        return true;
    }

    double minMaxDist(vector<int>& stations,int K) {
        n=stations.size();
        double l=0,h=1e6;
        while(h-l>1e-6){
            double m=l+(h-l)/2;
            if(help(stations,m,K)) h=m;
            else l=m;
        }
        return h;
    }
};