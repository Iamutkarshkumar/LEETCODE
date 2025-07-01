class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> v;
        unordered_set<char> s1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> s2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> s3 = {'z','x','c','v','b','n','m'};
        
        for (auto& ele : words) {
            int ans = 0;
            int n = ele.length();
            for (int i = 0; i < n; ++i) {
                char c = tolower(ele[i]);
                if (s1.count(c)) ans += 5;
                if (s2.count(c)) ans += 7;
                if (s3.count(c)) ans += 11;
            }
            
            // lowercase the first char once
            char c0 = tolower(ele[0]);
            bool allRow1 = (ans == n * 5)  &&  s1.count(c0);
            bool allRow2 = (ans == n * 7)  &&  s2.count(c0);
            bool allRow3 = (ans == n * 11) &&  s3.count(c0);
            
            if (allRow1 || allRow2 || allRow3)
                v.push_back(ele);
        }
        
        return v;
    }
};
