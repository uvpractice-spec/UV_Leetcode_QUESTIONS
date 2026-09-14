#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            
            if (i > maxReach) return false;

           
            maxReach = max(maxReach, i + nums[i]);

            
            if (maxReach >= n - 1) return true;
        }

        return true;
    }
};