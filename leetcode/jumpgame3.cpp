class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<arr.size();i++){
            if(i-arr[i]>=0) adj[i].push_back(i-arr[i]);
            if(i+arr[i]<n) adj[i].push_back(i+arr[i]);
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(start);
        vis[start]=1;
        int flag=0;
        while(!q.empty()){
            int node=q.front();
            if(arr[node]==0) return true;
            vis[node]=1;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    if(arr[it]==0) return true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};