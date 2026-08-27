class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        

        int totalSum = 0;
        
        int maxSoFar = nums[0], currentMax = 0;
        int minSoFar = nums[0], currentMin = 0;

        for (int num : nums) {
           
            currentMax = max(num, currentMax + num);
            maxSoFar = max(maxSoFar, currentMax);

         
            currentMin = min(num, currentMin + num);
            minSoFar = min(minSoFar, currentMin);

            totalSum += num;
        }

        
        if (maxSoFar < 0) {
            return maxSoFar;
        }

       
        return std::max(maxSoFar, totalSum - minSoFar);
    }
};