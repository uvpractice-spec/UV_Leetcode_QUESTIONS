class Solution {
public:
    int jump(vector<int>& nums) {
        
        
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);


        int n = nums.size();
        
        if(n <=1) return 0;
        int jump = 0;
        int curr = 0;
        int far = 0;


        for(int i=0;i<n-1;i++){

            far = max(far,i+nums[i]);

            if(far >= n - 1){
                return jump +1;
            }


            if(i == curr){
              jump++;
              curr = far;   
            }
        }

        return jump;

    }
};