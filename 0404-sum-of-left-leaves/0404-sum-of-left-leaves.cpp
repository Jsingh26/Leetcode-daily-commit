/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root ==nullptr) return 0;
        queue<TreeNode*> qt;
        int sum=0;
        qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            for(int i =0;i<size ;i++){
                TreeNode* node = qt.front();
                qt.pop();

                if(node->left) {

    if(node->left->left == nullptr &&
       node->left->right == nullptr) {

        sum += node->left->val;
    }

    qt.push(node->left);
}
                if(node->right){
                    qt.push(node->right);
                }

            }

        }
        return sum;
    }
};