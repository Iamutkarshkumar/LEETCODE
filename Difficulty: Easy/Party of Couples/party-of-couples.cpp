// User function Template for C++

class Solution {
  public:
    int findSingle(vector<int> &arr) {
        int ans=0;
        for(auto ele: arr) ans^=ele;
        return ans;
    }
};