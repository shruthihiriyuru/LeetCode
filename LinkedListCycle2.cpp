/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (head == NULL)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        
        if (fast->next == NULL || fast->next->next == NULL)
            return NULL;
        
        ListNode *tmp = slow;
        int n = 1;
        while (tmp->next != slow) {
            tmp = tmp->next;
            n++;
        }
        
        ListNode *first = head;
        ListNode *second = head;
        for (int i=0;i<n;i++) {
            second = second->next;
        }
        
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        
        return first;
        
        
    }
};
