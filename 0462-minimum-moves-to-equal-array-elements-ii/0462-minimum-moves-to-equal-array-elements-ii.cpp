class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int median = nums[n / 2];

        int sum = 0;
        for (int num : nums) {
            sum += abs(num - median);
        }

        return sum;
    }
};