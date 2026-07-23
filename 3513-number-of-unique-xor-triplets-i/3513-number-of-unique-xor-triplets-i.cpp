class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int numOfBits=0;
        int n=nums.size();
        if(n<3) return n;
        while(n){
            numOfBits++;
            n>>=1;
        }
        int x=(1<<numOfBits);
        return x;
    }
};