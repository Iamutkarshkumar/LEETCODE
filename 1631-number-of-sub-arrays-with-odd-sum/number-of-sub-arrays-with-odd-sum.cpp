class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0,ps=0,o=0,e=1;
        for(auto ele: arr){
            ps+=ele;
            if(ps%2==0){
                ans = (ans+o)%1000000007;
                e++;
            }
            else{
                ans = (ans+e)%1000000007;
                o++;
            }
        }
        return ans%1000000007;;
    }
};