class Solution {
public:
    bool checkValidString(string s) {
        int mask = 1;

        for (char ch : s) {
            if (ch == '(')
                mask = mask << 1;
            else if (ch == ')')
                mask = mask >> 1;
            else
                mask = (mask << 1) | mask | (mask >> 1);

            if (mask == 0)
                return false;
        }

        return (mask & 1) != 0;
    }
};