class Solution {
public:
    bool isPalindrome(string s) {
        // Here are the ASCII values:
        //     'A' is 65
        //     'Z' is 90
        //     'a' is 97
        //     'z' is 122
        //     Whitespace (space) is 32
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            while(i<j and not isalnum(s[i])) i++;
            while(i<j and not isalnum(s[j])) j--;
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;j--;
        }
        return true;
    }
};
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         // Here are the ASCII values:
//         //     'A' is 65
//         //     'Z' is 90
//         //     'a' is 97
//         //     'z' is 122
//         //     Whitespace (space) is 32

//         string help="";
//         for(auto ele: s){
//             if(ele-'A'>=0 and ele-'A'<=25) help.push_back(ele+32);
//             else if(ele-'a'>=0 and ele-'a'<=25) help.push_back(ele);
//             else if(ele-'a'>=-49 and ele-'a'<=-40) help.push_back(ele);
//             else continue;
//         }
//         // string x=help;
//         // reverse(begin(x),end(x));
//         int n=help.length();
//         for(int i=0;i<n/2;i++){
//             if(help[i]!=help[n-i-1]) return false;
//         }
//         return true;
//     }
// };