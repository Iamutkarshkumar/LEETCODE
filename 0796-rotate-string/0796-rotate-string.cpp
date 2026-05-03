class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        string temp=s+s;
        for(int i=0;i<n;i++){
            if(temp.substr(i,n)==goal) return true;
        }
        return false;
    }
};
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n=s.length();
//         for(int i=0;i<n;i++){
//             string temp=s;
//             reverse(begin(temp),begin(temp)+i);
//             reverse(begin(temp)+i,end(temp));
//             reverse(begin(temp),end(temp));
//             if(temp==goal) return true;
//         }
//         return false;
//     }
// };
