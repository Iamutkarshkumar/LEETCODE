// class Solution {
// public:
//     int dp[1001][1001];
//     bool ispredecessor (string a ,string b){
//         int n=a.length();
//         int m=b.length();
//         if(abs(m-n)!=1) return false;
//         int i=0,j=0;
//         while(i<n and j<m){
//             if(a[i]==b[j]){
//                 i++;j++;
//             }
//             else j++;
//         }
//         return i==n;
//     }
//     int solve(int i,int p,vector<string>& words){
//         if(i>=words.size()) return 0;
//         if(p!=-1 and dp[i][p]!=-1) return dp[i][p];

//         int take=0;
//         if(p==-1 or ispredecessor(words[p],words[i])){
//             take=1+solve(i+1,i,words);
//         }
//         int skip=solve(i+1,p,words);

//         if(p!=-1) return dp[i][p]=max(take,skip);
//         return max(take,skip);
//     }
//     static bool cmp(string a,string b){return a.length()<b.length();}
//     int longestStrChain(vector<string>& words) {
//         memset(dp,-1,sizeof(dp));
//         sort(words.begin(),words.end(),cmp);
//         return solve(0,-1,words);
//     }
// };
//Approach-2 (Using Simple LIS Bottom Up) - We sort it in the beginning to get words ordered in ascending order based on length
//T.C : O(n*n*n)
class Solution {
public:
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(m >= n || n-m != 1)
            return false;
        
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }
    
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words), end(words), myFunction); //You can select pairs in any order.
        
        vector<int> t(n, 1);
        int maxL = 1;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                
                if(predecessor(words[j], words[i])) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
        
    }
};