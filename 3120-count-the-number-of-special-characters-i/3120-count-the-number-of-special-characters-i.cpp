class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> avail;
        unordered_set<char> vis;
        int ans=0;
        for(auto ele: word){
            if(ele-'a'>=0 and ele-'a'<26) avail.insert(ele);
        }
        for(auto ele: word){
            if(ele-'A'>=0 and ele-'A'<26){
                if(vis.count(ele)==0 and avail.count(tolower(ele))){
                    vis.insert(ele);
                    ans++;
                }
            }
        }
        return ans;
    }
};