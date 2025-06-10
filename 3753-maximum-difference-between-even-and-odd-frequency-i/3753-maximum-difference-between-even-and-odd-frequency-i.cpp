class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26,0);
        int n=s.length();
        for(int i=0;i<n;i++) v[s[i]-'a']++;
        int mx_odd=0,mn_even=INT_MAX;
        for(auto ele: v){
            if(ele%2!=0) mx_odd=max(mx_odd,ele);
            else{
                if(ele!=0) mn_even=min(mn_even,ele);
            }
        }
        cout<<mx_odd<<" "<<mn_even;
        return mx_odd-mn_even;
    }
};