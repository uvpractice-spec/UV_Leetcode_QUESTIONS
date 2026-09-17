#include <vector>
#include <queue>
#include <cmath>
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = arr.size();
        queue<int> q;

        q.push(start);

        while(!q.empty()){

            int curr = q.front();

            q.pop();

            if(arr[curr] ==0 ) return true;
            
            if (arr[curr] < 0) continue;

            int jump = arr[curr];

            arr[curr] = -arr[curr];

            if(curr + jump < n){
                q.push(curr + jump);
            }

            if(curr - jump >= 0){
                q.push(curr - jump);
            }
        }


        return false;
    }
};