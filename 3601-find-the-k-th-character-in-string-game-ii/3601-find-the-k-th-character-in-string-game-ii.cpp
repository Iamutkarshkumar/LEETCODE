#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // p = atleast how many operation we need to perform to get k characrters
        int p= (ll)( log(k) / log(2) );
        int ct = 0;                 // how may positions we need to increment 'a'
        while( p >= 0 ){
            ll pw = pow(2 , p);     // length of string at pth operation
            if( k > pw ){
                k = k - pw;         // updating value of k after each operation
                if( operations[p] == 1 ) ct++; // if 1 we need to incrment 'a' by 1
             }
            p--;                    // back to previous operation
        }
        char ans = 'a' + ct % 26;  //increment the 'a' by ct positions( modulus by 26 so that ans remain b/w a-z)
        return ans;
    }
};