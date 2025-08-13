class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int startingPoint=0;
        int maxLen=1;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int L=1;L<=n;L++){//blue print codestorywithmik
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j) dp[i][i]=true;
                else if(i+1==j) dp[i][j]=(s[i]==s[i+1]);
                else dp[i][j]=(s[i]==s[j] and dp[i+1][j-1]);
            
                if (dp[i][j] && L > maxLen) {
                    maxLen = L;
                    startingPoint = i;
                }
            }
        }
        return s.substr(startingPoint,maxLen);
    }
};
// class Solution {
// public:
//     int dp[1001][1001];
//     bool isPalindrome(int i,int j,string& s){
//         if(i >= j) return dp[i][j] = true;        
//         if(dp[i][j] != -1) return dp[i][j];       
//         if(s[i] != s[j]) return dp[i][j] = false; 
//         return dp[i][j] = isPalindrome(i+1, j-1, s); 
//     }
//     string longestPalindrome(string s) {
//         memset(dp,-1,sizeof(dp));
//         int n=s.length();
//         int startingPoint=0;
//         int maxLen=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(isPalindrome(i,j,s)){
//                     int l=j-i+1;
//                     if(l>maxLen) {maxLen=l;startingPoint=i;}
//                 }
//             }
//         }
//         return s.substr(startingPoint,maxLen);
//     }
// };