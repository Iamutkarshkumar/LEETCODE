class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long mx=*max_element(ranks.begin(),ranks.end());
        long long l = 0;
        long long h = mx*cars*cars;
        long long ans=LLONG_MAX;

        while(l<=h){
            long long m = l+(h-l)/2;
            long long count=0;
            for(auto ele: ranks){
                count+=sqrt(m/ele);
            }
            if(count>cars){
                h=m-1;
                ans=min(ans,m);
            }
            else if(count<cars) l=m+1;
            else{
                ans=min(m,ans);
                h=m-1;
            }
        }
        return ans;
    }
};