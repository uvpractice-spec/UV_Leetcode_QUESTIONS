class Solution {
public:

    void helper_function(int idx,vector<int>& candidates, int target,std::vector<std::vector<int>> &result, std::vector<int> &current){

        if(target ==0){
            result.push_back(current);
            return;
        }

         if (target < 0) return;

        for(int i=idx;i<candidates.size();i++){

            if(candidates[i] > target) break;

            current.push_back(candidates[i]);

            helper_function(i,candidates,target-candidates[i],result,current);

            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        std::vector<std::vector<int>>result;
        std::vector<int> current;

        std::sort(candidates.begin(),candidates.end());

        helper_function(0,candidates,target,result,current);

        return result;
    }
};