class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        // DSU initialization
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Store {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        // Connect consecutive values
        for (int i = 1; i < n; i++) {

            if (arr[i].first - arr[i - 1].first <= limit) {
                unite(arr[i].second, arr[i - 1].second);
            }
        }

        // Group values belonging to the same component
        unordered_map<int, vector<int>> groups;

        for (auto [value, index] : arr) {
            groups[find(index)].push_back(value);
        }

        // Pointer for each component
        unordered_map<int, int> ptr;

        // Build lexicographically smallest array
        for (int i = 0; i < n; i++) {

            int root = find(i);

            nums[i] = groups[root][ptr[root]];

            ptr[root]++;
        }

        return nums;
    }
};