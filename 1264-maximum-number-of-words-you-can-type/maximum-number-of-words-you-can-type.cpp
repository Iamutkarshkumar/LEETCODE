class Solution {
public:
    vector<string> extractWords(const string &s){
        vector<string> res;
        int n = s.size(), i = 0;
        while(i < n){
            while(i < n && isspace((unsigned char)s[i])) i++;             // skip spaces
            if(i >= n) break;
            string cur;
            while(i < n && !isspace((unsigned char)s[i])) cur += s[i++]; // collect word
            res.push_back(cur);
        }
        return res;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> v;
        v=extractWords(text);
        unordered_set<char> set;
        int cannot=0;
        for(auto ele: brokenLetters) set.insert(ele);
        for(auto ele: v){
            for(auto x: ele){
                if(set.count(x)){
                    cannot++;
                    break;
                }
            }
        }
        return v.size()-cannot;
    }
};