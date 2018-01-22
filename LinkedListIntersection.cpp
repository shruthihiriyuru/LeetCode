
/*
160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

Approach 1:
Find the length of the two linked lists. Traverse the bigger list to advance it by abs(n1-n2).
Now traverse till the intersection point or the end.

Approach 2:
Move cur1 (cur2) forward from headA (headB) and loop back to headB (headA), 
eventually cur1 and cur2 will meet at the intersection point or nullptr.
*/


/* Approach 1 */
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0;
        int n2 = 0;
        ListNode* cur1;
        ListNode* cur2;
        
        ListNode* cur = headA;
        while(cur) {
            n1++;
            cur = cur->next;
        }
        
        cur = headB;
        while(cur) {
            n2++;
            cur = cur->next;
        }
        if (n1 > n2) {
            cur1 = headA;
            cur2 = headB;
        }
        else {
            cur1 = headB;
            cur2 = headA;
        }
        
        int count = 0;
        while (count < abs(n1-n2)) {
            cur1 = cur1->next;
            count++;
        }
        
        while (cur1 && cur2) {
            if (cur1 == cur2) {
                return cur1;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        return NULL;
        
    }
};


/* Approach 2 */

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
        if (p1 == NULL || p2 == NULL) return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            
            p1 = p1->next;
            p2 = p2->next;
            
            if (p1 == p2) 
                return p1;


            if (p1 == NULL) 
                p1 = headB;
            if (p2 == NULL) 
                p2 = headA;
        }
        
        return p1;
        
    }
};
