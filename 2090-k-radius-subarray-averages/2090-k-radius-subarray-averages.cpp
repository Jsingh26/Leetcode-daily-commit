class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        int len = 2 * k + 1;

        if (len > n) return ans;

        long long windowSum = 0;
        for (int i = 0; i < len; i++) {
            windowSum += nums[i];
        }

        ans[k] = windowSum / len;
        for (int i = len; i < n; i++) {
            windowSum += nums[i];
            windowSum -= nums[i - len];

            int center = i - k;
            ans[center] = windowSum / len;
        }

        return ans;
    }
};