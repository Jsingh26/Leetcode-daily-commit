class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        // cnt[d] = numbers divisible by d
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d) {
                cnt[d] += freq[m];
            }
        }

        vector<long long> exact(mx + 1, 0);

        // inclusion-exclusion
        for (int d = mx; d >= 1; d--) {
            long long pairs = cnt[d] * (cnt[d] - 1) / 2;

            for (int m = d * 2; m <= mx; m += d) {
                pairs -= exact[m];
            }

            exact[d] = pairs;
        }

        vector<long long> pref(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            pref[d] = pref[d - 1] + exact[d];
        }

        vector<int> ans;

        for (long long k : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), k + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};