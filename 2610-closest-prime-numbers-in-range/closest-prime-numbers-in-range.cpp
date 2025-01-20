class Solution {
public:
    vector<int> sieveOfEratosthenes(int l, int r){
        vector<int> primes(r+1,1);
        primes[0]=0;
        primes[1]=0;
        for(int i=2;i*i<=r;i++){
            if(primes[i]){
                for(int j=i*i;j<=r;j+=i){
                    primes[j]=0;
                }
            }
        }
        vector<int> v;
        for(int i=l;i<r+1;i++){
            if(primes[i]) v.push_back(i);
        }
        return v;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = sieveOfEratosthenes(left, right);
        if (primes.size() < 2) {
            return {-1, -1}; 
        }

        int minDiff = INT_MAX;
        pair<int, int> closestPair;

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                closestPair = {primes[i - 1], primes[i]};
            }
        }

        return {closestPair.first, closestPair.second};
    }
};