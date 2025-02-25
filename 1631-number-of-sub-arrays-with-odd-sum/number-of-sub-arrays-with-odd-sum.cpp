#define mod 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0,ps=0,o=0,e=1;
        for(auto ele: arr){
            ps+=ele;
            if(ps%2==0){
                ans = (ans+o)%mod;
                e++;
            }
            else{
                ans = (ans+e)%mod;
                o++;
            }
        }
        return ans%mod;
    }
};