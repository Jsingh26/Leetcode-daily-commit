class Solution {
public:
    TreeNode* minvalue(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == nullptr)
            return nullptr;

        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{

            // Case 1: Leaf node
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }

            // Case 2: One child
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* temp = minvalue(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right,temp->val);
        }

        return root;
    }
};