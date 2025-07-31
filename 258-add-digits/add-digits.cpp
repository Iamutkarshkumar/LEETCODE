class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            string s=to_string(num);
            int sum=0;
            for(auto ele: s) sum+=ele-'0';
            num=sum;
        }
        return num;
    }
};