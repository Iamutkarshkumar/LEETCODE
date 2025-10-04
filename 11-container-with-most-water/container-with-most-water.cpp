class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            int len=min(height[i],height[j]);
            ans=max(ans,len*(j-i));

            if(height[i]==len) i++;
            else j--;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n=height.size();
//         int ans=INT_MIN;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int area=min(height[i],height[j])*(j-i);
//                 ans=max(ans,area);
//             }
//         }
//         return ans;
//     }
// };