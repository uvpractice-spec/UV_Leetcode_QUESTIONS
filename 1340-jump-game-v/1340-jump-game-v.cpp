class Solution {
public:
    int solve(int ind, int d, vector<int>& arr, vector<int>& dp){
        if(ind<0 || ind>=arr.size()) return 0;

        if(dp[ind] != -1) return dp[ind];
        int ans=0;
        for(int i=1;i<=d && ind+i < arr.size();i++){
            if(arr[ind+i] >= arr[ind]) break;
            ans=max(ans, 1+solve(ind+i,d,arr,dp));   
        }

        for(int i=1;i<=d && ind-i>=0;i++){
            if(arr[ind-i] >= arr[ind]) break;
            ans=max(ans, 1+solve(ind-i,d,arr,dp));
        }

        return dp[ind]=ans;
    }
      
    int maxJumps(vector<int>& arr, int d) {
        
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        

      int n=arr.size();
        vector<int> dp (n, -1);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,1+solve(i,d,arr,dp));
        return ans; 
      
    }
};