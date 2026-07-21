class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return topo.size() == numCourses ? topo : vector<int>{};
    }
};