class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum=0;
        for(auto ele: derived) sum^=ele;
        if(sum==0) return true;
        else return false;
    }
};