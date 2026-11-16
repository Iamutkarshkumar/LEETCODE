class Solution {
public:
    int n;
    void help(string& s,int k){
        int i=0;
        int sum=0;
        int counter=0;
        string temp;
        while(i<n){
            sum+=(s[i]-'0');
            counter++;
            if(counter==k){
                temp+=(to_string(sum));
                sum=0;
                counter=0;
            }
            i++;
        }
        if(counter>0) temp+=to_string(sum);
        s=temp;
        n=s.length();
    }
    string digitSum(string s, int k) {
        stack<char> st;
        n=s.length();
        while(s.length()>k){
            help(s,k);
        }
        return s;
    }
};