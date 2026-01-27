//approach 1: Line Sweep 
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        vector<pair<int,int>> v;
        for(auto ele: start) v.push_back(make_pair(ele,1));
        for(auto ele: end) v.push_back(make_pair(ele,-1));
        sort(v.begin(),v.end());
        
        int ans=0,curr=0;
        for(auto ele: v){
            curr+=ele.second;
            ans=max(ans,curr);
        }
        return ans;
    }
};
//approach 2: Difference array technique
// class Solution {
//   public:
//     int minMeetingRooms(vector<int> &start, vector<int> &end) {
//         int n=start.size();
//         int maxEle=*max_element(end.begin(),end.end());
//         vector<int> v(maxEle+2,0);
//         for(int i=0;i<n;i++){
//             v[start[i]]+=1;
//             v[end[i]]-=1;
//         }
//         for(int i=1;i<v.size();i++) v[i]+=v[i-1];
//         return *max_element(v.begin(),v.end());
//     }
// };
