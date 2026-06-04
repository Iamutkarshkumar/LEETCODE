class Solution {
public:
    int wave(int ele){
        int count=0;
        string s=to_string(ele);
        int n=s.length();
        for(int i=1;i<n-1;i++){
            if((s[i]>s[i-1] and s[i]>s[i+1]) or (s[i]<s[i-1] and s[i]<s[i+1])) count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        if(num2<100) return 0;
        for(int i=num1;i<=num2;i++) ans+=wave(i);
        return ans;
    }
};