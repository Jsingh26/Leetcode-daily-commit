class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp;

        for(int num : nums) {
            mp.insert(num);
        }

        for(int i = 1; i <= nums.size(); i++) {
            if(mp.count(i * k)) {
                continue;
            }
            return i * k;
        }

        return (nums.size() + 1) * k;
    }
};