class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxseq = 1;
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                maxseq++;
            } else {
                maxseq = 1;
            }
            ans = max(ans, maxseq);
        }
        return ans;
    }
};