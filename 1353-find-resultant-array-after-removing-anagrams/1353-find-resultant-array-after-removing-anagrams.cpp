class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(256, 0);
        for (char c : s) freq[c]++;
        for (char c : t) freq[c]--;

        for (int x : freq)
            if (x != 0) return false;
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int i=0,j=1;
        while(j<words.size()){
            if(isAnagram(words[i],words[j])) j++;
            else{
                ans.push_back(words[i]);
                i=j;
                j++;
            }
        }
        ans.push_back(words[i]);
        return ans;
    }
};