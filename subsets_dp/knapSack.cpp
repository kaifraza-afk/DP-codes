class Solution
{
    public:
   int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
            vector<vector<int>>dp(n,vector<int>(W+1,0));
            for (int j = 0; j <= W; j++) {
                dp[0][j] = (j / wt[0]) * val[0];
            }
            for(int i=0;i<n;i++){
                for(int j=1;j<=W;j++){
                    int pick=0,notpick=0;
                    if(j-wt[i]>=0) pick=val[i]+dp[i][j-wt[i]];
                    notpick=dp[i-1][j];
                    dp[i][j]=max(pick,notpick);
                }
            }
            return dp[n-1][W];
       }
};
