//TLE
// class Solution {
// public:
//     bool allUniqueChar(string& s){
//         unordered_set<char> set;
//         for(auto ele: s) set.insert(ele);
//         return s.length()==set.size();
//     }
//     int maxLength(vector<string>& arr) {
//         int n=arr.size();
//         int maxLen=INT_MIN;
//         for(int mask=0;mask<(1<<n);mask++){
//             string s="";
//             for(int i=0;i<n;i++){
//                 if(mask&(1<<i)){
//                     s+=arr[i];
//                 }
//             }
//             bool check=allUniqueChar(s);
//             if(check) maxLen=max(maxLen,(int)s.length());
//         }
//         return maxLen;
//     }
// };
class Solution {
public:
    bool notAllUnique(string a,string b){
        unordered_set<char> s;
        for(auto ele: a) s.insert(ele);
        for(auto ele: b) s.insert(ele);
        int aLen=a.length();
        int bLen=b.length();
        if(s.size()<(aLen+bLen)) return true;
        return false;
    }
    unordered_map<string,int> dp;
    int solve(int i,int n,vector<string>& arr,string temp){
        if(i>=n) return temp.length();

        string key=to_string(i)+"_"+temp;
        if(dp.count(key)) return dp[key];
        int exclude=0,include=0;
        if(notAllUnique(temp,arr[i])) exclude=solve(i+1,n,arr,temp);
        else{
            exclude=solve(i+1,n,arr,temp);
            include=solve(i+1,n,arr,temp+arr[i]);
        }
        return dp[key]=max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        dp.clear();
        string temp="";
        int n=arr.size();
        return solve(0,n,arr,temp);
    }
};