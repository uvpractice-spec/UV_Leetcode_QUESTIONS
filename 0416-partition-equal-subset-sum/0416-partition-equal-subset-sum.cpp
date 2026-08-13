class Solution {
public:
    int summ(vector<int> num){
        int result=0;
        for(auto x : num){
            result+=x;
        }

        return result;
    }
    bool canPartition(vector<int>& nums) {
        
        int add=summ(nums);
        
      
        if(add % 2!=0) return false;

        int target = add/2;
        

        vector<bool> dp(target+1,false);
        dp[0]=true;

        for(int num : nums){

            for(int j=target;j>=num;j--){

                if(dp[j-num]){
                    dp[j]=true;
                }
            }

            if(dp[target]) return true;
        }

       return dp[target];
    }
};