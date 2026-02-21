class Solution {
public:
    vector<int> sieveOfEratosthenes(int n){
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
        vector<int> v;
        for(int i=0;i<n+1;i++){
            if(primes[i]) v.push_back(i);
        }
        return v;
    }
    int countPrimeSetBits(int left, int right) {
        vector<int> help;
        help=sieveOfEratosthenes(right);
        int ans=0;
        for(int i=left;i<=right;i++){
            int x=__builtin_popcount(i);
            if(binary_search(begin(help),end(help),x)) ans++;
        }
        return ans;
    }
};