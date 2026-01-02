class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        int n=v.size();
        if(n==0) return {-1,-1};

        int l=0,h=n-1;
        int start=-1,end=-1;

        // lower bound (first occurrence)
        while(l<=h){
            int m=l+(h-l)/2;
            if(v[m]>=t) h=m-1;
            else l=m+1;
        }
        if(l<n && v[l]==t) start=l;

        // upper bound (last occurrence)
        l=0; h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(v[m]<=t){
                if(v[m]==t) end=m;
                l=m+1;
            } 
            else h=m-1;
        }

        return {start,end};
    }
};

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& v, int t) {
//         int start=-1,end=-1;
//         if(binary_search(v.begin(),v.end(),t)){
//             start=lower_bound(v.begin(),v.end(),t)-begin(v);
//             end=upper_bound(v.begin(),v.end(),t)-begin(v)-1;
//         }
//         return {start,end};
//     }
// };