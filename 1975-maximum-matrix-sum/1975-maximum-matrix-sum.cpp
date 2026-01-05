using ll=long long;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll ans=0;
        ll count=0;
        ll smallestVal=INT_MAX;
        for(auto ele: matrix){
            for(auto x: ele){
                ans+=abs(x);
                if(x<0) count++;
                smallestVal=min(smallestVal,abs((ll)x));
            }
        } 
        if(count%2==0) return ans;
        else return ans-2*smallestVal;
    }
};