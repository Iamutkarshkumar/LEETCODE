class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.length();
        int ans=0;
        for(string ele: patterns){
            ans+=(word.find(ele)!=string::npos);
        }
        return ans;
    }
};