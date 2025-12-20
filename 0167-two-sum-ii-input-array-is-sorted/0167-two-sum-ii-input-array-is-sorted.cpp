class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int n=num.size();
        int i=0,j=n-1;
        while(i<j){
            int x=num[i]+num[j];
            if(x==t) return {i+1,j+1};
            else if(x>t) j--;
            else i++;
        }
        return {};
    }
};