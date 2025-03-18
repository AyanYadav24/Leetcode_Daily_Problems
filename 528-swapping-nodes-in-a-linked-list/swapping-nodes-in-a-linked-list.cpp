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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head, *begin = head, *end = head;
        while(temp){
            n++;
            temp = temp -> next;
        }
        int k1 = k;
        while(--k1){
            begin = begin -> next;
        }
        k = n-k;
        while(k--){
            end = end -> next;
        }
        cout << end -> val;
        int value = end -> val;
        end -> val = begin -> val;
        begin -> val = value;
    return head;
    }
};