class Solution {
public:

    void helper( vector<vector<int>> &result ,vector<int> &curr ,vector<int> &nums,  vector<bool> &visited){

        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size();i++){
            
            if (visited[i]) continue; 
            
            visited[i] = true;
            curr.push_back(nums[i]);

            helper(result,curr,nums,visited);

            curr.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
      vector<vector<int>> result;
      vector<int> curr;
      
      vector<bool> visited(nums.size(), false);
      helper(result,curr,nums,visited);

      return result;
      
    }
};