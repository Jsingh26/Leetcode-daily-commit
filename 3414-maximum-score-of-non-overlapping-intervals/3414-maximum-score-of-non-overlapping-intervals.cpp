class Solution {
public:

    struct State {
        long long score = 0;
        vector<int> ids;
    };

    State better(const State& a, const State& b) {

        // Higher score is better
        if (a.score != b.score) {
            return (a.score > b.score) ? a : b;
        }

        // Same score -> lexicographically smaller indices
        if (lexicographical_compare(
                a.ids.begin(), a.ids.end(),
                b.ids.begin(), b.ids.end())) {
            return a;
        }

        return b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {left, right, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by left endpoint
        sort(a.begin(), a.end());

        // Store all left endpoints for binary search
        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        // next[i] = first interval whose left > a[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            int j = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();

            next[i] = j;
        }

        // dp[i][k]
        // maximum answer from i onward
        // using at most k intervals
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip this interval
                State skip = dp[i + 1][k];

                // Option 2: take this interval
                State take = dp[next[i]][k - 1];

                take.score += a[i][2];

                take.ids.push_back((int)a[i][3]);

                // We need indices sorted
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].ids;
    }
};