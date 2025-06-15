class Solution {
public:
    int maxDiff(int num) {
        string str1=to_string(num);
        string str2=str1;
        int idx;
        for(int i=0;i<str1.length();i++){
            if(str1[i]!='9'){
                idx=i;
                break;
            }
        }
        char x=str1[idx];
        replace(str1.begin(),str1.end(),x,'9');

        for(int i=0;i<str2.length();i++){
            char x=str2[i];
            if(i==0){
                if(x!='1'){
                    replace(str2.begin(),str2.end(),x,'1');
                    break;
                }
            }
            else if(x!='0' and x!=str2[0]){
                replace(str2.begin(),str2.end(),x,'0');
                break;
            }
        }
        return stoi(str1)-stoi(str2);
    }
};