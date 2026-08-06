class Solution {
public:
    ListNode* findMiddle(ListNode* head, ListNode* tail) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    TreeNode* build(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;

        ListNode* mid = findMiddle(head, tail);
        TreeNode* root = new TreeNode(mid->val);

        root->left = build(head, mid);
        root->right = build(mid->next, tail);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, nullptr);
    }
};