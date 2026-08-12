class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        std::vector<unsigned int> dp(target + 1, 0);

        dp[0]=1;
        // target 
        // how to build a 1-inch tower, then 2-inch, then 3-inch...
        for(int i=1;i<=target;i++){
            // block size
            for(int block : nums){

                if(block <= i){
                   dp[i]+=dp[i-block];  // look back previous ans in dp
                }
            }
        }

        return dp[target];
    }
};