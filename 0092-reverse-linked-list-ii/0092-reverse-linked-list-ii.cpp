class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // dummy node simplifies the "left == 1" edge case
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevLeft = dummy;

        // walk prevLeft to the node just before position `left`
        for (int i = 0; i < left - 1; i++) {
            prevLeft = prevLeft->next;
        }

        // standard reversal, starting at the node at position `left`
        ListNode* prev = nullptr;
        ListNode* curr = prevLeft->next;
        for (int i = 0; i <= right - left; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        
        prevLeft->next->next = curr;   // connect reversed segment's tail to the rest of the list
        prevLeft->next = prev;         // connect the front part to the reversed segment's new head

        return dummy->next;
    }
};