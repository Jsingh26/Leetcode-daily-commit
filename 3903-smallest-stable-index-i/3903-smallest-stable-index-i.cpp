class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int max1 = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            max1 = max(max1, nums[i]);

            int min1 = *min_element(nums.begin() + i, nums.end());

            if (max1 - min1 <= k) {
                return i;
            }
        }

        return -1;
    }
};