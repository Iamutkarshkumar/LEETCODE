class Solution {
public:
    int timeToSec(string t){
        int h = stoi(t.substr(0,2));
        int m = stoi(t.substr(3,2));
        int s = stoi(t.substr(6,2));
        return h * 3600 + m * 60 + s;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        int startSec=timeToSec(startTime);
        int endSec=timeToSec(endTime);
        return endSec-startSec;
    }
};