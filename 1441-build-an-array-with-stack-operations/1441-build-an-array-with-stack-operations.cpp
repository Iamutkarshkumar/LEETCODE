class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for(int i=1;i<=min(n,target[target.size()-1]);i++){
            if(binary_search(begin(target),end(target),i)){
                ans.push_back("Push");
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};