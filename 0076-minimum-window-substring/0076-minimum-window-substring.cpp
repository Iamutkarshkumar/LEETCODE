class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n) return "";
        int minLen=INT_MAX;
        int idx;
        int counter=t.length();
        unordered_map<char,int> mp;
        for(auto ele: t) mp[ele]++;

        int i=0,j=0;
        while(j<n){
            char ch_j = s[j];
            if(mp[ch_j]>0) counter--;
            mp[ch_j]--;
            while(counter==0){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    idx=i;
                }
                char ch_i=s[i];
                mp[ch_i]++;
                if(mp[ch_i]>0) counter++;
                i++;
            }
            j++;
        }
        return (minLen==INT_MAX ? "" : s.substr(idx,minLen));
    }
};