// class Solution {
// public:
//     string addSpaces(string s, vector<int>& spaces) {
//         long long i=0;
//         for(auto ele: spaces){
//             s.insert(ele+i, " ");
//             i++;
//         }
//         return s;
//     }
// };
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int n = s.size();
        int m = spaces.size();
        int spaceIdx = 0; // Pointer for spaces vector
        
        for (int i = 0; i < n; i++) {
            if (spaceIdx < m && i == spaces[spaceIdx]) {
                result += ' '; // Add a space at the required position
                spaceIdx++;    // Move to the next space index
            }
            result += s[i]; // Add the current character
        }
        return result;
    }
};
