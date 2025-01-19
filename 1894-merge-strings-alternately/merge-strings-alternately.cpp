class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0;
        int j=0;
        int x=min(word1.length(), word2.length());

        // Merging alternately until one of the strings is exhausted
        while (i < x && j < x) {
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }

        // Append remaining characters from the longer string
        while (i < word1.length()) {
            ans.push_back(word1[i]);
            i++;
        }

        while (j < word2.length()) {
            ans.push_back(word2[j]);
            j++;
        }

        return ans;
    }
};