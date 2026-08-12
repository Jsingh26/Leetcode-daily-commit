class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int max_length = 0;
        int count = 0;
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {

            freq[nums[i]]++;
            count++;

            while (freq[nums[i]] > k) {
                freq[nums[left]]--;
                left++;
                count--;
            }

            max_length = max(max_length, count);
        }

        return max_length;
    }
};