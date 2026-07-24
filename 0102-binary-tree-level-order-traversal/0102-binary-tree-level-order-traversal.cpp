class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {

                TreeNode* currentNode = q.front();
                q.pop();

                level.push_back(currentNode->val);

                if(currentNode->left)
                    q.push(currentNode->left);

                if(currentNode->right)
                    q.push(currentNode->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};