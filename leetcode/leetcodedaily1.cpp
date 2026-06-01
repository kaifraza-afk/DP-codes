class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0,n=cost.size(),steps=0;
        sort(cost.begin(),cost.end());
        for(int i=n-1;i>=0;i--){
            if(steps==2){
                steps=0;
                continue;
            }
            ans=ans+cost[i];
            steps++;
        }
        return ans;
    }
};