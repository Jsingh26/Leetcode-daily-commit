class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; i--) {
            int best = INT_MIN;
            int take = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                best = max(best, take - dp[(i + k + 1) % 4]);
            }

            dp[i % 4] = best;
        }

        int diff = dp[0];

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};