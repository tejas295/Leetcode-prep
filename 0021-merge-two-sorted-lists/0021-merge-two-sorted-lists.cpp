/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head;
        if(temp1->val <= temp2->val) {
            head = temp1;
            temp1 = temp1->next;
        }
        else {
            head = temp2;
            temp2 = temp2->next;
        }
        ListNode* curr = head;
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val <= temp2->val) {
                curr->next = temp1;
                temp1 = temp1->next;
            }
            else {
                curr->next = temp2;
                temp2 = temp2->next;
            }
            curr = curr->next;
        }
        if(temp1 != NULL) curr->next = temp1;
        else curr->next = temp2;

        return head;
    }
};