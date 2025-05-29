class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int l =0,r=arr.size()-1;
        int max_water=0;
        while(l<r){
            int h=min(arr[l],arr[r]);
            int w=r-l;
            max_water=max(max_water,h*w);
            if(arr[l]<arr[r]) l++;
            else r--;
        }
        return max_water;
    }
};