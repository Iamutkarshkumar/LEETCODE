class Solution {
public:
    bool isvowel(int i){
        char c=i+'a';
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u'){
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        vector<int> freq(26);
        for(int i=0;i<s.length();i++) freq[s[i]-'a']++;
        int v=0,c=0;
        for(int i=0;i<26;i++){
            if(isvowel(i)) v=max(v,freq[i]);
            else c=max(c,freq[i]);
        }
        return v+c;
    }
};