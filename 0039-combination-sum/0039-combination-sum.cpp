class Solution {
public:

    vector<int> temp;

    void solve(vector<int>& nums, int target, int sum,
               vector<vector<int>>& ans, int i) {

        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        if (i >= nums.size() || sum > target) {
            return;
        }

   
        temp.push_back(nums[i]);
        solve(nums, target, sum + nums[i], ans, i);
        temp.pop_back();
        solve(nums, target, sum, ans, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        solve(nums, target, 0, ans, 0);
        return ans;
    }
};
