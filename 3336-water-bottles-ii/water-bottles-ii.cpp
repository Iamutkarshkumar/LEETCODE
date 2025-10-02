class Solution {
public:
    int maxBottlesDrunk(int numBottles,int numExchange){
        int full=numBottles, empty=0, drunk=0, cost=numExchange;
        while(true){
            // drink everything we have
            drunk += full;
            empty += full;
            full = 0;
            // if we have enough empties for one exchange at current cost, do exactly one
            if(empty < cost) break;
            empty -= cost;
            full += 1;
            cost += 1;
        }
        return drunk;
    }
};
