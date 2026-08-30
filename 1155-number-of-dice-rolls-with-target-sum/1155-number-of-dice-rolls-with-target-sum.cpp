class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // 0 dice -> sum 0
        dp[0][0] = 1;

        for (int dice = 1; dice <= n; dice++) {

            for (int sum = 1; sum <= target; sum++) {

                for (int face = 1; face <= k; face++) {

                    if (sum - face >= 0) {
                        dp[dice][sum] =
                            (dp[dice][sum] + dp[dice - 1][sum - face]) % MOD;
                    }
                }
            }
        }

        return dp[n][target];
    }
};