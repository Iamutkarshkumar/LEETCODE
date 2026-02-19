class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr_g=1, prev_g=0; int ret = 0;
        int l = s.length();
        for(int i=1; i<l; i++)
        {
            if(s[i]==s[i-1])
                curr_g++;
            else
            {
                ret+= min(curr_g,prev_g);
                prev_g = curr_g;
                curr_g=1;
            }
        }
        return ret + min(curr_g, prev_g);
    }
};