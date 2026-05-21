class Solution {
public:
    int lenOfInt(int a){
        int len=0;
        while(a){
            a/=10;
            len++;
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto ele: arr1){
            int x=ele;
            while(x){
                st.insert(x);
                x/=10;
            }
        }
        int ans=0;
        for(auto ele: arr2){
            int x=ele;
            while(x){
                if(st.count(x)){
                    ans=max(ans,lenOfInt(x));
                    break;
                }
                x/=10;
            }
        }
        return ans;
    }
};