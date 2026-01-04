using ll=long long;
class Solution {
public:
    vector<ll> countDivisors(int ele){
        ll cnt=0,sum=0;
        for(ll i=1;i*i<=ele;i++){
            if(ele%i==0){
                if(i*i==ele){
                    cnt++;
                    sum+=i;
                }
                else{
                    cnt+=2;
                    sum+=i + ele/i;
                }
            }
        }
        return {cnt,sum};
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto ele: nums){
            auto count=countDivisors(ele);
            if(count[0]==4) ans+=count[1];
        }
        return ans;
    }
};