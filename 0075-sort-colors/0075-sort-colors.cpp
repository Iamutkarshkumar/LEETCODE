class Solution {
public:
    void sortColors(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1;
        int i=0;
        while(i<=r){
            if(v[i]==0){
                swap(v[i],v[l]);
                l++;
                i++;
            }
            else if(v[i]==2){
                swap(v[i],v[r]);
                r--;
            }
            else i++;
        }
    }
};
// class Solution {
// public:
//     void sortColors(vector<int>& num) {
//         priority_queue<int,vector<int>,greater<int>> pq(num.begin(),num.end());
//         vector<int> v(num.size());
//         for(int i=0;i<num.size();i++){
//             num[i]=pq.top();
//             pq.pop();
//         }
//     }
// };