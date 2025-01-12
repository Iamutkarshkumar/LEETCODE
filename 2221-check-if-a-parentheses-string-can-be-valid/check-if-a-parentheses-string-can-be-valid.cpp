class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false; // Length must be even
        
        int open = 0, flexible = 0;

        // Check from left to right
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                ++flexible; // Unlocked can act as '(' or ')'
            } else if (s[i] == '(') {
                ++open; // Locked '('
            } else { // Locked ')'
                if (open > 0) {
                    --open; // Pair with an open '('
                } else if (flexible > 0) {
                    --flexible; // Use an unlocked parenthesis as '('
                } else {
                    return false; // Not enough '(' to balance
                }
            }
        }

        // At this point, open + flexible must cover all '(' needed
        if (open > flexible) return false;

        open = 0; 
        flexible = 0;

        // Check from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                ++flexible; // Unlocked can act as '(' or ')'
            } else if (s[i] == ')') {
                ++open; // Locked ')'
            } else { // Locked '('
                if (open > 0) {
                    --open; // Pair with a close ')'
                } else if (flexible > 0) {
                    --flexible; // Use an unlocked parenthesis as ')'
                } else {
                    return false; // Not enough ')' to balance
                }
            }
        }

        return open <= flexible;
    }
};
