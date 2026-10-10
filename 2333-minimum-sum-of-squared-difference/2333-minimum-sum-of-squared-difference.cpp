class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int mx = 0;
        vector<long long> cnt(100001, 0);
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            mx = max(mx, d);
        }

        for (int d = mx; d >= 1 && k > 0; d--) {
            if (cnt[d] == 0) continue;
            if (k >= cnt[d]) {
                cnt[d - 1] += cnt[d];
                k -= cnt[d];
                cnt[d] = 0;
            } else {
                cnt[d - 1] += k;
                cnt[d] -= k;
                k = 0;
            }
        }

        long long ans = 0;
        for (long long d = 1; d <= mx; d++) ans += cnt[d] * d * d;
        return ans;
    }
};