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
        if (head==NULL || head->next==NULL)
        return NULL;

        ListNode* dhere = head;
        ListNode* tez = head;


        while (tez && tez->next) {
            dhere = dhere->next;
            tez = tez->next->next;

            if (dhere == tez) {
            
                ListNode* entry = head;
                while (entry != dhere) {
                    entry = entry->next;
                    dhere = dhere->next;
                }
                return entry; 
            }
        }

        return NULL;
    }
};
