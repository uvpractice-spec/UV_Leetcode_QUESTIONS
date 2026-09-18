class Solution {
public:
    int minJumps(vector<int>& arr) {
        

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        

        int n= arr.size();
        
        if(n <= 1) return 0;

        unordered_map<int,vector<int>> vtoind;

        for(int i=0;i<n;i++){
            vtoind[arr[i]].push_back(i);
        }

        queue<int> q;

        vector<bool> visited(n,false);


        q.push(0);
        visited[0]=true;

        int steps =0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                int curr = q.front();

                q.pop();

                if(curr == n-1) return steps;

                if(curr + 1 < n && !visited[curr+1]){
                    visited[curr+1]=true;
                    q.push(curr+1);
                }

                if(curr - 1 >=0 && !visited[curr - 1] ){
                    visited[curr-1] = true;
                    q.push(curr -1);
                }

                int val = arr[curr];

                if(vtoind.count(val)){

                    for(int ind : vtoind[val]){

                        if(!visited[ind]){
                            visited[ind]= true;
                            q.push(ind);

                        }
                    }

                    vtoind.erase(val);
                }
            }
            steps++;
        }

        return -1;
    }
};