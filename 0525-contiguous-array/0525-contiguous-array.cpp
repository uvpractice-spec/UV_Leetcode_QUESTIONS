class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        
        vector<int> firstSeen(2 * n + 1, -2);
        
        int offset = n; 
       
        firstSeen[0 + offset] = -1;

        int runningSum = 0;
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
          
            runningSum += (nums[i] == 1) ? 1 : -1;

           
            int mappedindex = runningSum + offset;

            if (firstSeen[mappedindex] != -2) {
               
                maxLength = max(maxLength, i - firstSeen[mappedindex]);
            } else {
            
                firstSeen[mappedindex] = i;
            }
        }

        return maxLength;
    }
};