class Solution {
public:
    int MinCost(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int index = i; index <= j; index++) {
            int cost =
                cuts[j + 1] - cuts[i - 1] +
                MinCost(i, index - 1, cuts, dp) +
                MinCost(index + 1, j, cuts, dp);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int k = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(k + 2, vector<int>(k + 2, -1));

        return MinCost(1, k, cuts, dp);
    }
};