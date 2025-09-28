class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        int i=v.size()-3;
        std::sort(begin(v),end(v));
        while(i>=0){
            if(v[i]+v[i+1]>v[i+2]) return v[i]+v[i+1]+v[i+2];
            i--;
        }
        return 0;
    }
};