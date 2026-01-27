class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n=start.size();
        int maxEle=*max_element(end.begin(),end.end());

        vector<int> v(maxEle+2,0);   // FIX HERE

        for(int i=0;i<n;i++){
            v[start[i]]++;
            v[end[i]]--;
        }

        for(int i=1;i<v.size();i++) v[i]+=v[i-1];

        return *max_element(v.begin(),v.end());
    }
};
