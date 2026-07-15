class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        stack<int> st;

        st.push(source);
        visited[source] = true;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (node == destination)
                return true;

            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    st.push(nei);
                }
            }
        }

        return false;
    }
};