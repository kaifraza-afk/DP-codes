class Solution {
public:

    static bool cmp(string &str1, string &str2) {
        return str1.size() < str2.size();
    }

    bool compare(string str1, string str2) {

        if (str1.size() != str2.size() + 1)
            return false;

        int left = 0, right = 0;

        while (left < str1.size()) {

            if (right < str2.size() &&
                str1[left] == str2[right]) {
                left++;
                right++;
            }
            else {
                left++;
            }
        }

        return right == str2.size();
    }

    int longestStrChain(vector<string>& words) {

        int n = words.size();

        if (n == 0)
            return 0;

        sort(words.begin(), words.end(), cmp);

        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (compare(words[i], words[j]) &&
                    dp[j] + 1 > dp[i]) {

                    dp[i] = dp[j] + 1;
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};