class Solution {
public:
    using ll = long long;

    long long countCommas(long long n) {
        ll ans = 0;

        for (ll start = 1000; start <= n; start *= 10) {
            ll end = min(n, start * 10 - 1);

            ll commas = 1;
            ll x = start;

            while (x >= 1000000) {
                x /= 1000;
                commas++;
            }

            ans += (end - start + 1) * commas;
        }

        return ans;
    }
};