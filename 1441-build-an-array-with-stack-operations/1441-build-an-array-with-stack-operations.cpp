class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i=0,stream=1;
        while(i<target.size() and stream<=n){
            ans.push_back("Push");
            if(target[i]==stream){
                i++;
                stream++;
            }
            else{
                ans.push_back("Pop");
                stream++;
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<string> buildArray(vector<int>& target, int n) {
//         vector<string> ans;
//         unordered_set<int> s;
//         for(auto ele: target) s.insert(ele);
//         for(int i=1;i<=min(n,target[target.size()-1]);i++){
//             if(s.count(i)){
//                 ans.push_back("Push");
//             }
//             else{
//                 ans.push_back("Push");
//                 ans.push_back("Pop");
//             }
//         }
//         return ans;
//     }
// };