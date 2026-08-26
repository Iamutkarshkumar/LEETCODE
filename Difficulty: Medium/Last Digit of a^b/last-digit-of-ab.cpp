class Solution {
  public:
    int modulo(int d, string &b)
    {
        int mod = 0;

        // calculate (b mod d) to make
        // b in range 0 <= b < d
        for (int i = 0; i < b.length(); i++)
            mod = (mod * 10 + b[i] - '0') % d;

        return mod;
    }
    int getLastDigit(string& a, string& b) {
        // code here
        int n = a.length(), m = b.length();

        // exponent is 0
        if (m == 1 && b[0] == '0')
            return 1;

        // base is 0
        if (n == 1 && a[0] == '0')
            return 0;

        // if exponent is divisible by 4 that means last
        // digit will be pow(a, 4) % 10
        // otherwise last digit will be pow(a, b%4) % 10
        int exp = (modulo(4, b) == 0) ? 4 : modulo(4, b);
        int res = pow(a[n - 1] - '0', exp);
        return res % 10;
        
    }
};