class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size(),i=0,j=0;
        int ans=0;
        int trueCount=0;
        while(j<n){
            if(answerKey[j]=='T') trueCount++;
            if((j-i+1)-trueCount<=k) ans=max(ans,j-i+1);
            else{
                if(answerKey[i]=='T') trueCount--;
                i++;
            }
            j++;
        }
        int falseCount=0;
        i=0,j=0;
        while(j<n){
            if(answerKey[j]=='F') falseCount++;
            if((j-i+1)-falseCount<=k) ans=max(ans,j-i+1);
            else{
                if(answerKey[i]=='F') falseCount--;
                i++;
            }
            j++;
        }
        return ans;
    }
};