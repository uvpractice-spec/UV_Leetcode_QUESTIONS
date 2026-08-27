class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int prefixSum = 0;
        int maxPrefix = 0;
        int minPrefix = 0;

        for (int x : nums) {
            prefixSum += x;
            maxPrefix = max(maxPrefix, prefixSum);
            minPrefix = min(minPrefix, prefixSum);
        }

        return maxPrefix - minPrefix;
    }
};