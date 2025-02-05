class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int n=s1.length();
        vector<int> s1freq(26,0);
        vector<int> s2freq(26,0);
        int diff=0;
        for(int i=0;i<n;i++){
            char s1char=s1[i];
            char s2char=s2[i];
            if(s2char!=s1char) diff++;
            s1freq[s1char-'a']++;
            s2freq[s2char-'a']++;
        }
        if(diff>2) return false;
        for(int i=0;i<26;i++){
            if(s1freq[i]!=s2freq[i]) return false;
        }
        return true;
    }
};