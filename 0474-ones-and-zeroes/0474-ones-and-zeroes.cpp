class Solution {
public:
    int dp[601][101][101];

    int solve(vector<pair<int,int>>& cnt, int m, int n, int i) {

        if(i == cnt.size())
            return 0;

        if(dp[i][m][n] != -1)
            return dp[i][m][n];

        int take = 0;

        if(cnt[i].first <= m &&
           cnt[i].second <= n)
        {
            take = 1 + solve(
                cnt,
                m - cnt[i].first,
                n - cnt[i].second,
                i + 1
            );
        }

        int skip = solve(cnt, m, n, i + 1);

        return dp[i][m][n] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        memset(dp, -1, sizeof(dp));

        vector<pair<int,int>> cnt;

        for(auto &s : strs) {

            int zeros = 0;
            int ones = 0;

            for(char ch : s) {
                if(ch == '0')
                    zeros++;
                else
                    ones++;
            }

            cnt.push_back({zeros, ones});
        }

        return solve(cnt, m, n, 0);
    }
};