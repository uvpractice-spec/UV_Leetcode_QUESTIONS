class Solution {
public:
     void helper( const std::vector<int> &nums, 
                   std::vector<int> &curr, 
                   std::vector<std::vector<int>>& result, vector<bool> &visited) {
      
      if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }

      for(int i= 0 ;i<nums.size();i++){
        
       
       
        
        if (visited[i]) continue; 
            
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

        visited[i] = true;

       

        curr.push_back(nums[i]);

        helper(nums,curr,result,visited);

        curr.pop_back();
        visited[i]=false;
      }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         std::sort(nums.begin(), nums.end());
        std::vector<int> curr;
         std::vector<std::vector<int>> result;
        
         vector<bool> visited(nums.size(), false);
         helper(nums,curr,result,visited);

         return result; 
    }
};