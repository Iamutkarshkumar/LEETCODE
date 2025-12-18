class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        //base case
        if(n==1){
            // cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
            return 1;
        }
        
        int count=towerOfHanoi(n-1,from,aux,to);
        // cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        count++;
        count+=towerOfHanoi(n-1,aux,to,from);
        return count;
    }
};