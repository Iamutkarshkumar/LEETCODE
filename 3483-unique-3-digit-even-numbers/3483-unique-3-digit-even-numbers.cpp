class Solution {
public:
    vector<int> freq;
    bool check(int x){
        vector<int> v(10,0);
        while(x){
            int last=x%10;
            v[last]++;
            x/=10;
        }
        for(int i=0;i<10;i++)
            if(v[i]>freq[i]) return false;

        return true;
    }
    int totalNumbers(vector<int>& digits) {
        freq.assign(10,0);
        for(auto ele: digits) freq[ele]++;

        int ans=0;
        for(int i=100;i<=998;i+=2){
            if(check(i)) ans++;
        }
        return ans;
    }
};
