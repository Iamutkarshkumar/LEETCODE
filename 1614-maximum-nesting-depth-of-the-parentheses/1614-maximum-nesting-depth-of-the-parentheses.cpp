class Solution {
public:
    int maxDepth(string s) {
    int currentDepth = 0;
    int maxDepth = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            currentDepth++;

            if(currentDepth > maxDepth){
                maxDepth = currentDepth;
            }
        }
        if(s[i] == ')'){
        currentDepth--;
        }
    }

    return maxDepth ;
    }
};