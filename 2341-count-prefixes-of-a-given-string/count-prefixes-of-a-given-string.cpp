class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count=0;
        for(auto ele: words){
            if(s.find(ele)==0) count++;
        }
        return count;
    }
};