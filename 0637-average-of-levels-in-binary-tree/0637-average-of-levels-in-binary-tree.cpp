class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> arr;

        if(root == nullptr) return arr;

        queue<TreeNode*> qt;
        qt.push(root);

        while(!qt.empty()) {

            int size = qt.size();
            long long sum = 0;

            for(int i = 0; i < size; i++) {

                TreeNode* currentNode = qt.front();
                qt.pop();

                sum += currentNode->val;

                if(currentNode->left)
                    qt.push(currentNode->left);

                if(currentNode->right)
                    qt.push(currentNode->right);
            }

            arr.push_back((double)sum / size);
        }

        return arr;
    }
};