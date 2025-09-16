class Solution {
public:
    unordered_set<int> sieveOfEratosthenes(int n){
        vector<int> primes(n+1,1);
        primes[0]=0;
        primes[1]=0;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }
        }
        unordered_set<int> v;
        for(int i=0;i<n+1;i++){
            if(primes[i]) v.insert(i);
        }
        return v;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto ele: nums) mp[ele]++;
        int n=nums.size();
        unordered_set<int> s;
        s=sieveOfEratosthenes(n);
        for(auto ele: mp){
            if(s.count(ele.second)) return true;
        } 
        return false;
    }
};