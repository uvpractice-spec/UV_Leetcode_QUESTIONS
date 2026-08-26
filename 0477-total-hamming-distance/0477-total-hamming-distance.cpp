class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int n = nums.size();
        int totalDistance = 0;
        
       
        for (int i = 0; i < 32; i++) {
            int countOnes = 0;
            
           
            for (int num : nums) {
                countOnes += (num >> i) & 1;
            }
            
            int countZeros = n - countOnes;
            totalDistance += countOnes * countZeros;
        }
        
        return totalDistance;
    }
};