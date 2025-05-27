

class Solution {
  public:
    int findMissing(vector<int>& arr1, vector<int>& arr2) {
        for(auto ele: arr2) arr1.push_back(ele);
        int ans=0;
        for(auto ele: arr1) ans^=ele;
        return ans;
    }
};