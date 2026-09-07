class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        int n = s.size();

        // dp[i] = number of distinct subsequences
        // including the empty subsequence
        vector<long long> dp(n + 1);

        dp[0] = 1;

        // Last occurrence of each character
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {

            // Normally every subsequence can:
            // 1. not take s[i]
            // 2. take s[i]
            dp[i + 1] = (2 * dp[i]) % MOD;

            int c = s[i] - 'a';

            // If this character appeared before,
            // remove the duplicate subsequences.
            if (last[c] != -1) {
                dp[i + 1] = (dp[i + 1] - dp[last[c]] + MOD) % MOD;
            }

            last[c] = i;
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};