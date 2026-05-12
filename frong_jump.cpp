class Solution {
public:
    int frogJump(vector<int>& heights) {

        int n = heights.size();

        if(n == 0 || n == 1)
            return 0;

        vector<int> dp(n);

        dp[0] = 0;
        dp[1] = abs(heights[1] - heights[0]);

        for(int i = 2; i < n; i++) {

            int oneStep =
                abs(heights[i] - heights[i-1]) + dp[i-1];

            int twoStep =
                abs(heights[i] - heights[i-2]) + dp[i-2];

            dp[i] = min(oneStep, twoStep);
        }

        return dp[n-1];
    }
}; 