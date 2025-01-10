class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); // stores freq of combined word formed
        vector<string> ans;

        for (int i = 0; i < words2.size(); i++) {
            vector<int> freq(26, 0);
            for (auto it : words2[i]) {
                freq[it - 'a'] += 1;
                maxFreq[it - 'a'] = max(maxFreq[it - 'a'], freq[it - 'a']);
            }
        }

        for (string w : words1) {
            vector<int> freq(26, 0);
            for (auto it : w) {
                freq[it - 'a']++;
            }

            for (int i = 0; i <= 26; i++) {
                if (i == 26) {
                    ans.push_back(w);
                } 
                else if (maxFreq[i] > freq[i]) // condition for when w is not a superset of the combined word
                    break;
            }
        }

        return ans;
    }
};