class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        int ans=0;

        for(int d:digits) freq[d]++;

        for(int u=0;u<=8;u+=2){
            if(!freq[u]) continue;

            freq[u]--;

            for(int h=1;h<=9;h++){
                if(!freq[h]) continue;

                freq[h]--;

                for(int t=0;t<=9;t++)
                    if(freq[t]) ans++;

                freq[h]++;
            }

            freq[u]++;
        }

        return ans;
    }
};