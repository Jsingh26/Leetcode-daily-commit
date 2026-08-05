class Solution {
public:
    unordered_set<int> st;

    bool dfs(TreeNode* root, int k) {

        if (root == nullptr)
            return false;

        if (st.count(k - root->val))
            return true;

        st.insert(root->val);

        return dfs(root->left, k) || dfs(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};