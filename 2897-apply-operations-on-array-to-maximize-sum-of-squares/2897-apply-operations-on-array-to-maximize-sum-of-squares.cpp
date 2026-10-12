class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> arr(k, 0);

        // Distribute each set bit among k numbers
        for (int bit = 0; bit < 31; bit++) {
            int count = 0;

            for (int num : nums) {
                if (num & (1 << bit)) {
                    count++;
                }
            }

            for (int i = 0; i < min(count, k); i++) {
                arr[i] |= (1LL << bit);
            }
        }

        long long ans = 0;

        for (long long x : arr) {
            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};