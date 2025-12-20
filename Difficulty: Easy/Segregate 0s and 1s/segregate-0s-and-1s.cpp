// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]==1 and arr[j]==0) swap(arr[i++],arr[j--]);
            else if(arr[i]==0) i++;
            else if(arr[j]==1) j--;
        }
    }
};