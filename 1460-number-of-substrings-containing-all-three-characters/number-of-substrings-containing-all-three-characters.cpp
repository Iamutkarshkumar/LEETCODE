class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0,j=0,count=0;
        while(j<n){
            mp[s[j]]++;
            while(mp['a']>=1 and mp['b']>=1 and mp['c']>=1){
                count+=(n-j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};
