class Solution {
public:
    int perfectSum(vector<int>& arr, int K) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        // Sum 0 is always possible
        dp[0][0] = 1;

        // Handle first element
        if (arr[0] == 0)
            dp[0][0] = 2; // take or not take
        else if (arr[0] <= K)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= K; j++) {

                int notTake = dp[i - 1][j];

                int take = 0;
                if (j >= arr[i])
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][K];
    }
};