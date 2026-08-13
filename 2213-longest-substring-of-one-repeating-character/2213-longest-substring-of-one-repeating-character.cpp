class Solution {
public:
    struct Node {
        int len = 0;
        int pref = 0;   // length of run of leftmost char from the start
        int suf = 0;    // length of run of rightmost char till the end
        int best = 0;   // best (longest) single-char run in this segment
        char leftCh = 0;
        char rightCh = 0;
    };

    vector<Node> tree;
    string str;
    int n;

    Node merge(const Node& a, const Node& b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;
        Node res;
        res.len = a.len + b.len;
        res.leftCh = a.leftCh;
        res.rightCh = b.rightCh;

        res.pref = a.pref;
        if (a.pref == a.len && a.rightCh == b.leftCh) {
            res.pref += b.pref;
        }

        res.suf = b.suf;
        if (b.suf == b.len && b.leftCh == a.rightCh) {
            res.suf += a.suf;
        }

        res.best = max(a.best, b.best);
        if (a.rightCh == b.leftCh) {
            res.best = max(res.best, a.suf + b.pref);
        }
        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].len = 1;
            tree[node].pref = 1;
            tree[node].suf = 1;
            tree[node].best = 1;
            tree[node].leftCh = str[l];
            tree[node].rightCh = str[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*node+1, l, mid);
        build(2*node+2, mid+1, r);
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].leftCh = c;
            tree[node].rightCh = c;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node+1, l, mid, idx, c);
        else update(2*node+2, mid+1, r, idx, c);
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        n = s.size();
        tree.assign(4 * n, Node());
        build(0, 0, n - 1);

        int k = queryCharacters.size();
        vector<int> result(k);

        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            update(0, 0, n - 1, idx, c);
            result[i] = tree[0].best;
        }

        return result;
    }
};