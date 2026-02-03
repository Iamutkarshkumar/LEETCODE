class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        int maxKbooking=0,curr=0;
        for(auto ele: mp){
            curr+=ele.second;
            maxKbooking=max(curr,maxKbooking);
        }
        return maxKbooking;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */