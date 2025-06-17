class Solution {
    static const int MOD = 1e9+7;
    long long modPow(long long a,long long e){
        long long r=1;
        while(e){
            if(e&1) r=r*a%MOD;
            a=a*a%MOD;
            e>>=1;
        }
        return r;
    }
    long long comb(int n,int r){
        if(r<0||r>n) return 0;
        vector<long long> f(n+1),inv(n+1);
        f[0]=1;
        for(int i=1;i<=n;i++) f[i]=f[i-1]*i%MOD;
        inv[n]=modPow(f[n],MOD-2);
        for(int i=n;i>0;i--) inv[i-1]=inv[i]*i%MOD;
        return f[n]*inv[r]%MOD*inv[n-r]%MOD;
    }
public:
    int countGoodArrays(int n,int m,int k){
        // need n-k-1 >= 0
        if(k>n-1) return 0;
        long long p = m * modPow(m-1, n-k-1) % MOD;
        long long c = comb(n-1, k);
        return p * c % MOD;
    }
};
