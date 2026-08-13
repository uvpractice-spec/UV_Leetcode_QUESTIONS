class Solution {
public:

    void helper(int idx, const std::vector<int> &nums, 
                   std::vector<int> &curr, 
                   std::vector<std::vector<int>>& result) {

      result.push_back(curr);

      for(int i= idx ;i<nums.size();i++){
        

        if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }

        curr.push_back(nums[i]);

        helper(i+1,nums,curr,result);

        curr.pop_back();
      }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        std::vector<int> curr;
         std::vector<std::vector<int>> result;

         helper(0,nums,curr,result);

         return result; 

    }
};