class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int empty=numBottles;
        while(empty>numExchange){
            int convert=empty/numExchange;
            int left=empty%numExchange;
            empty=left+convert;
            ans+=convert;
        }
        ans+=empty/numExchange;
        return ans;
    }
};