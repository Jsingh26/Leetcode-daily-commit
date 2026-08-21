class Solution {
public:

    void solve(vector<int>& candidates, int target, int sum,
               vector<int> temp, vector<vector<int>>& ans, int i) {

        if(sum == target) {
            ans.push_back(temp);
            return;
        }

        for(int j = i; j < candidates.size(); j++) {

            // Skip duplicates at the same level
            if(j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }

            // Since sorted, no later element will work either
            if(sum + candidates[j] > target) {
                break;
            }

            temp.push_back(candidates[j]);

            solve(candidates,
                  target,
                  sum + candidates[j],
                  temp,
                  ans,
                  j + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, temp, ans, 0);

        return ans;
    }
};