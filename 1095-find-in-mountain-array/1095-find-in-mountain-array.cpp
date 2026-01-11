/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int BSAes(MountainArray &arr,int l,int r,int t){
        while(l<=r){
            int m=l+(r-l)/2;
            int val=arr.get(m);
            if(val==t) return m;
            if(val<t) l=m+1;
            else r=m-1;
        }
        return -1;
    }

    int BSDes(MountainArray &arr,int l,int r,int t){
        while(l<=r){
            int m=l+(r-l)/2;
            int val=arr.get(m);
            if(val==t) return m;
            if(val>t) l=m+1;   // reversed
            else r=m-1;
        }
        return -1;
    }
    int findPivot(MountainArray &arr){
        int l=0,r=arr.length()-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(arr.get(m)<arr.get(m+1)) l=m+1;
            else r=m;
        }
        return l;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int pivot=findPivot(mountainArr);

        int idx=BSAes(mountainArr,0,pivot-1,target);
        if(idx!=-1) return idx;
        idx=BSDes(mountainArr,pivot,n-1,target);
        return idx;
    }
};