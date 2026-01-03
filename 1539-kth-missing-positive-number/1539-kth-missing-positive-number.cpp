class Solution {
public:

    //O(log(n))
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            
            int missingTillMid=arr[m]-(m+1);
            if(missingTillMid<k) l=m+1;
            else r=m-1;
        }
        return l+k;
    }
};
// class Solution {
// public:

//     //O(n)
//     int findKthPositive(vector<int>& arr, int k) {
//         int n=arr.size();
//         int i=0;
//         int num=1;
//         while(i<n and k>0){
//             if(arr[i]==num) i++;
//             else k--;
//             num++;
//         }
//         while(k--) num++;
//         return num-1;
//     }
// };