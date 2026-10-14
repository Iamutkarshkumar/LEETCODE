class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int numOfNine=sum/9;
        int remDigit=sum-(numOfNine*9);
        int totalPlaces=numOfNine;
        if(remDigit>0) totalPlaces++;
        if(totalPlaces>num) return "";

        string ans;
        while(numOfNine--){
            ans.push_back('9');
            num--;
        } 
        if(remDigit>0){
            ans.push_back(remDigit+'0');
            num--;
        } 
        while(num--) ans.push_back('0');
        return ans;
    }
};