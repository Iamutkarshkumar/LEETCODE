class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        //t[i][j] = true : s[i:j] is a substring where i and j are inclusive indices

        int count = 0;

        for(int L = 1; L <= n; L++) {
            for(int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if(i == j) {
                    t[i][i] = true; //Single characters are palindrome
                } else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]); //Strings of 2 Length
                } else {
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1] == true);
                }

                count += t[i][j];
            }
        }

        return count;
    }
};

// class Solution {
// public:
//     int dp[1001][1001];
//     bool checkPalindrome(int i, int j,string& s){
//         if(i>=j) return dp[i][j]=true;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==s[j]) return dp[i][j]=checkPalindrome(i+1,j-1,s);
//         return dp[i][j]=false;
//     }
//     int countSubstrings(string s) {
//         int n=s.length();
//         memset(dp,-1,sizeof(dp));
//         int ans=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 ans+=checkPalindrome(i,j,s);
//             }
//         }
//         return ans;
//     }
// };