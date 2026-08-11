class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums[0];
        int i = 1;

        // extend prefix sum while it stays consecutive
        while (i < n && nums[i] - nums[i-1] == 1) {
            sum += nums[i];
            i++;
        }

        unordered_set<int> present(nums.begin(), nums.end());

        // find smallest integer >= sum not present in nums
        while (present.count(sum)) {
            sum++;
        }

        return sum;
    }
};