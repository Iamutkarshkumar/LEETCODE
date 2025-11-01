

class Solution {
    // Function to find the leaders in the array.
  public:
   vector<int> leaders(vector<int>& arr) {
        vector<int> res; 
        int n = arr.size();
    
        // Start with the rightmost element
        int maxRight = arr[n - 1]; 
    
        // Rightmost element is always a leader
        res.push_back(maxRight); 
        
        // Traverse the array from right to left
        for (int i = n - 2; i >= 0; i--) {
    
            if (arr[i] >= maxRight) {
                maxRight = arr[i]; 
                res.push_back(maxRight); 
            }
        }
    
        // Reverse the result array to maintain
        // original order
        reverse(res.begin(), res.end());
        
        return res; 
    }
};