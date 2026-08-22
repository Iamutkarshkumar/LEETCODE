class Solution {
  public:
    int minimumStep(int n) {
        // code here
        
        int step=0;
        int v=0;
        
       while(n>1){
           
           if(n%3==0){
               
               n=n/3;
               step++;
           }
           else{
               
               n=n-1;
               step++;
           }
       }
       return step;
    }
};