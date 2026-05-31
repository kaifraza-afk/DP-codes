class Solution {
public:
    int MaxCoins(int i, int j, vector<int>& nums,
                 vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = 0;

        for (int index = i; index <= j; index++) {
            int cost =
                nums[i - 1] * nums[index] * nums[j + 1] +
                MaxCoins(i, index - 1, nums, dp) +
                MaxCoins(index + 1, j, nums, dp);

            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return MaxCoins(1, n, nums, dp);
    }
};