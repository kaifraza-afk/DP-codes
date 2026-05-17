class Solution {
public:
    int mod = 1e9 + 7;

    int perfectSum(vector<int>& arr, int K) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        // Base Case
        if (arr[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;

            if (arr[0] <= K)
                dp[0][arr[0]] = 1;
        }

        for (int i = 1; i < n; i++) {

            for (int target = 0; target <= K; target++) {

                int notTake = dp[i - 1][target];

                int take = 0;

                if (arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];

                dp[i][target] = (take + notTake) % mod;
            }
        }

        return dp[n - 1][K];
    }

    int countPartitions(vector<int>& arr, int diff) {

        int totalSum = 0;

        for (int x : arr)
            totalSum += x;

        // Invalid case
        if ((totalSum + diff) % 2 != 0)
            return 0;

        int target = (totalSum + diff) / 2;

        return perfectSum(arr, target);
    }
};