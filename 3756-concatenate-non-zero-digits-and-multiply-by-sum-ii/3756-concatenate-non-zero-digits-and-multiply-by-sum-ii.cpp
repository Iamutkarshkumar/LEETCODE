// class Solution {
// public:
//     using ll = long long;
//     const ll MOD = 1000000007;

//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//         int n = s.length();
//         int m = queries.size();

//         vector<int> ans(m);
//         vector<ll> prefixSum(n);
//         vector<string> prefixNum(n);

//         for (int i=0;i<n;i++){
//             if (i==0){
//                 prefixSum[i] = s[i]-'0';
//                 if (s[i]!='0') prefixNum[i] += s[i];
//             } 
//             else{
//                 prefixSum[i] = prefixSum[i-1] + (s[i]-'0');
//                 prefixNum[i] = prefixNum[i-1];
//                 if(s[i]!='0') prefixNum[i] += s[i];
//             }
//         }

//         for(int i=0;i<m;i++){
//             int l=queries[i][0],r=queries[i][1];
//             ll sum=prefixSum[r]-(l>0 ? prefixSum[l-1] : 0);
//             string tempR=prefixNum[r];
//             string tempL=(l>0 ? prefixNum[l-1] : "");
//             int lenL=tempL.size();
//             int lenR=tempR.size();
//             string temp=tempR.substr(lenL,lenR-lenL);
        
//             ll prod=0;
//             for(auto ele: temp){
//                 prod = (prod*10 + ele-'0')%MOD;
//             }
//             ans[i]=(sum*prod)%MOD;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> nonZeroCount(n, 0);    // non-zero digits count in s[0..i]
        vector<ll> numberUpTo(n, 0);      // number formed from non-zero digits in s[0..i]
        vector<ll> digitSumUpTo(n, 0);    // digit sum of s[0..i]
        vector<ll> pow10(n + 1, 0);  // 10^i

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;


        nonZeroCount[0]      = (s[0] != '0') ? 1 : 0;
        numberUpTo[0]   = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0)
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % MOD;
            else
                numberUpTo[i] = numberUpTo[i - 1];
        }

        for (int i = 1; i < n; i++) {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + (s[i] - '0');
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++) {
            int l  = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            ll numBefore   = (l == 0) ? 0 : numberUpTo[l - 1];

            int endCount = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                result[i] = 0;
                continue;
            }

            ll x   = (numberUpTo[r] - (numBefore * pow10[subStrLen] % MOD) + MOD) % MOD;
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((x * sum) % MOD);
        }

        return result;
    }
};