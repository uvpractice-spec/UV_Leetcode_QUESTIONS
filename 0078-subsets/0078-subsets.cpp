class Solution {
public:

    void helper(int idx, const std::vector<int> &nums, 
                   std::vector<int> &curr, 
                   std::vector<std::vector<int>>& result) {
       
        result.push_back(curr);
        
        
        for (int i = idx; i < nums.size(); ++i) {
           
            curr.push_back(nums[i]);
            
           
            helper(i + 1, nums, curr, result);
            
           
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
      std::vector<std::vector<int>> result;
        std::vector<int> currentPath;
        
        helper(0, nums, currentPath, result);
        
        return result;
    }
};