/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
*/


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
    int getLinkedListLength(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        while (cur) {
            count++;
            cur = cur->next;
        }
        return count;
    }
    
    ListNode* reverseList(ListNode* head, int p, int k) {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *cur = head;
        int i = k;
        
        while (cur != NULL && i--) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        p--;
        
        if (p)
            head->next = reverseList(next, p, k);
        else
            head->next = next;
        
        return prev;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getLinkedListLength(head);
        if (n < k)
            return head;
        
        int p = n/k;
        return reverseList(head, p, k);
    }
};
