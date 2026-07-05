class Solution {
public:
    pair<int,int> help(int x){
        int small=INT_MAX,large=INT_MIN;
        int n=x;
        while(n){
            int a=n%10;
            n/=10;
            small=min(small,a);
            large=max(large,a);
        }
        return {large-small,x};
    }
    int maxDigitRange(vector<int>& nums) {
        vector<pair<int,int>> v;// {maxDigitRange,ele}
        int maxRange=INT_MIN;
        for(int &ele: nums){
            pair<int,int> temp=help(ele);
            v.push_back(temp);
            maxRange=max(maxRange,temp.first);
        }
        int sum=0;
        for(auto &ele: v){
            if(ele.first==maxRange) sum+=ele.second;
        }
        return sum;
    }
};