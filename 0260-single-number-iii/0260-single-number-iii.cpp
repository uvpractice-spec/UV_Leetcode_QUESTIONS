class Solution {
public:

    vector<int> singleNumber(vector<int>& nums) {
        
        long long xor_sum=0;

        for(int x : nums){
            xor_sum^=x;
        }

        long long right_most_bit = xor_sum &(-xor_sum);

        int a=0,b=0;

        for(int num : nums){

            if(num & right_most_bit){
                a^=num;
            }else{
                b^=num;
            }
        }


        return {a,b};
        
    }
};