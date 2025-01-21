class Solution {
public:
    const int MOD = 1e9 + 7;

    int sieveOfEratosthenes(int n) {
        vector<int> primes(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = 0;
                }
            }
        }
        int count = 0;
        for (int i = 2; i <= n; i++) {
            if (primes[i]) count++;
        }
        return count;
    }

    int modFactorial(int x) {
        long long prod = 1;
        for (int i = 1; i <= x; i++) {
            prod = (prod * i) % MOD;
        }
        return prod;
    }

    int numPrimeArrangements(int n) {
        int primeCount = sieveOfEratosthenes(n);
        int compCount = n - primeCount;
        long long primeFact = modFactorial(primeCount);
        long long compFact = modFactorial(compCount);
        return (primeFact * compFact) % MOD;
    }
};
