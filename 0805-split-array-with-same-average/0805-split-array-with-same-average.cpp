class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int N=nums.size();
        int n1=N/2;
        int n2=N-n1;
        int S=accumulate(begin(nums),end(nums),0);
        unordered_map<int,vector<int>> sumLeft; // size -> {subsetSums}
        for(int mask=0;mask<(1<<n1);mask++){
            int count=0;
            int sum=0;
            for(int i=0;i<n1;i++){
                if(mask&(1<<i)){
                    sum+=nums[i];
                    count++;
                }
            }
            sumLeft[count].push_back(sum);
        }
        unordered_map<int,vector<int>> sumRight; // size -> {subsetSums}
        for(int mask=0;mask<(1<<n2);mask++){
            int count=0;
            int sum=0;
            for(int i=0;i<n2;i++){
                if(mask&(1<<i)){
                    sum+=nums[n1+i];
                    count++;
                }
            }
            sumRight[count].push_back(sum);
        }

        for(int count=0;count<=n2;count++){
            sort(begin(sumRight[count]),end(sumRight[count]));
        }

        for(int k=0;k<=n1;k++){
            for(int leftSubSum : sumLeft[k]){
                for(int m=0;m<=n2;m++){
                    int size=k+m;
                    if(size==0 or size==N) continue;
                    if(size*S%N!=0) continue;
                    int rightSubSum=size*S/N-leftSubSum;

                    if(binary_search(begin(sumRight[m]),end(sumRight[m]),rightSubSum)) return true;
                }
            }
        }
        return false;
    }
};