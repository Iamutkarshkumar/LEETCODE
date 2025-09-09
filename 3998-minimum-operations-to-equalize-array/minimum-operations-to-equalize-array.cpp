class Solution {
public:
    int minOperations(vector<int>& n) {
        for(int i=1;i<n.size();i++){
            if(n[i]!=n[i-1]) return 1;
        }
        return 0;
    }
};