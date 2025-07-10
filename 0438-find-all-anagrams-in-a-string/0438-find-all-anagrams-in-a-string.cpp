class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len_s=s.length();
        int len_p=p.length();
        if(len_p>len_s) return {};
        vector<int> freq_p(26,0),freq_window(26,0),ans;
        
        for(int i=0;i<len_p;i++){
            freq_p[p[i]-'a']++;
            freq_window[s[i]-'a']++;
        }
        if(freq_p==freq_window) ans.push_back(0);
        int i=0,j=len_p;
        while(j<len_s){
            freq_window[s[j++]-'a']++;
            freq_window[s[i++]-'a']--;
            if(freq_p==freq_window) ans.push_back(i);
        }        
        return ans;
    }
};