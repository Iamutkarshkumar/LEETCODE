class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int mergedStart = meetings[0][0];
        int mergedEnd = meetings[0][1];
        int freeDays = 0;
        for (int i = 1; i < n; i++) {
            if (meetings[i][0] <= mergedEnd) {
                mergedEnd = max(mergedEnd, meetings[i][1]);
            } 
            else {
                freeDays += meetings[i][0] - mergedEnd - 1;
                mergedStart = meetings[i][0];
                mergedEnd = meetings[i][1];
            }
        }
        freeDays += meetings[0][0] - 1;
        freeDays += days - mergedEnd;
        return freeDays;
    }
};
