class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = -1;
        int secondLargest = -1;
        int idx = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
                idx = i;
            } else if (nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }

        return (largest >= 2 * secondLargest) ? idx : -1;
    }
};