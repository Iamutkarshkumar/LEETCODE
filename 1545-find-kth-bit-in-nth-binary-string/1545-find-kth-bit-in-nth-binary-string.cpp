// class Solution {
// public:
//     string help(string x){
//         string ans="";
//         for(int i=x.length()-1;i>=0;i--){
//             x[i]=='1'? ans.push_back('0'):ans.push_back('1');
//         }
//         return ans;
//     }
//     char findKthBit(int n, int k) {
//         vector<string> v(n);
//         v[0]="0";
//         for(int i=1;i<n;i++){
//             string s=help(v[i-1]);
//             v[i]=v[i-1]+"1"+s;
//         }
//         return v[n-1][k-1];
//     }
// };
class Solution {
public:
    string help(string x){
        string ans="";
        for(int i=x.length()-1;i>=0;i--)
            ans.push_back(x[i]=='1'?'0':'1');
        return ans;
    }

    char findKthBit(int n, int k) {
        vector<string> v(n);
        v[0]="0";

        for(int i=1;i<n;i++){
            string s=help(v[i-1]);
            v[i]=v[i-1]+"1"+s;
        }

        return v[n-1][k-1];
    }
};