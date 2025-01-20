class Solution {
public:
    vector<bool> sieve(int& n){
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
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime = sieve(n);
        vector<vector<int>> result;

        for (int i = 2; i <= n / 2; i++) {
            int j = n - i;
            if (isPrime[i] && isPrime[j]) {
                result.push_back({i, j});
            }
        }
        return result;
    }
};