class Solution {
public:
    
    vector<bool> sieve(int n){
        vector<bool> primes(n+1,true);
        primes[0]=false;
        primes[1]=false;
        for(int i=2;i*i<n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=false;
                }
            }
        }
        return primes;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> help;
        help=sieve(105);
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(help[nums[i]]) v.push_back(i);
        }
        sort(v.begin(),v.end());
        int x=v.size();
        return v[x-1] - v[0];
    }
};