class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int index = 1;
        
        while (curr->next != nullptr) {
            
            ListNode* next = curr->next;
            
            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);
            
            if (isCritical) {
                
                // First critical point
                if (first == -1) {
                    first = index;
                }
                // We already have a previous critical point
                if (last != -1) {
                    minDist = min(minDist, index - last);
                }   
                last = index;
            }
            prev = curr;
            curr = next;
            index++;
        }
    
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        int maxDist = last - first;
        return {minDist, maxDist};
    }
};