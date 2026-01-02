class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t) {
        int start=-1,end=-1;
        if(binary_search(n.begin(),n.end(),t)){
            start=lower_bound(n.begin(),n.end(),t)-begin(n);
            end=upper_bound(n.begin(),n.end(),t)-begin(n)-1;
        }
        
        return {start,end};
    }
};