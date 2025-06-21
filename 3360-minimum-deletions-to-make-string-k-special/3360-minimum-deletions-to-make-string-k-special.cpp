class Solution {
public:
    int minimumDeletions(string word, int k) {
        // 1) count frequencies
        unordered_map<char,int> freq;
        for(char c: word) 
            freq[c]++;
        
        // 2) move them into a vector and sort
        vector<int> v;
        for(auto &p: freq) 
            v.push_back(p.second);
        sort(v.begin(), v.end());
        
        int n = v.size();
        int ans = word.size();  // worst case: delete everything
        
        // 3) try every possible "low" = v[i]
        for(int i = 0; i < n; ++i){
            int low = v[i];
            int high = low + k;
            int deletions = 0;
            
            // 4) delete all below 'low', and delete excess above 'high'
            for(int j = 0; j < n; ++j){
                if(v[j] < low) 
                    deletions += v[j];
                else if(v[j] > high) 
                    deletions += (v[j] - high);
            }
            
            ans = min(ans, deletions);
        }
        
        return ans;
    }
};
