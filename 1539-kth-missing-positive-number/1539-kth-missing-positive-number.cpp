class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int counter=0;
        int i=1;
        while(true){
            if(!binary_search(begin(arr),end(arr),i)) counter++;
            if(counter==k) return i;
            i++;
            
        }
        return -1;
    }
};