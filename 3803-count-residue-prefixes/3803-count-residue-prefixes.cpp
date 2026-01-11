class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> set;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            set.insert(s[i]);
            if(set.size()==(i+1)%3) ans++;
        }
        return ans;
    }
};