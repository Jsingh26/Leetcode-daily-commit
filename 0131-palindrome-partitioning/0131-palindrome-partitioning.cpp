class Solution {
public:

    bool palindrome(string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(string& s, int index,
               vector<string>& temp,
               vector<vector<string>>& ans) {

        if(index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < s.size(); i++) {

            if(palindrome(s, index, i)) {

                temp.push_back(s.substr(index, i - index + 1));

                solve(s, i + 1, temp, ans);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, temp, ans);

        return ans;
    }
};