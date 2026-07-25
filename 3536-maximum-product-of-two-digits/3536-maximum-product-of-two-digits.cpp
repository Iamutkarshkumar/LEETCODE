class Solution {
public:
    using ll=long long;
    int maxProduct(int n) {
        ll largest=LLONG_MIN,second_Largest=LLONG_MIN;
        while(n){
            int x=n%10;n/=10;
            if(x>largest){
                second_Largest=largest;
                largest=x;
            }
            else if(x>second_Largest) second_Largest=x;
        }
        return largest*second_Largest;
    }
};