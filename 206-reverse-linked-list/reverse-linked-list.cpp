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
    ListNode* solve(ListNode* prev, ListNode* curr, ListNode* fwd){
        if(!curr) return prev;
        fwd = fwd -> next;
        curr -> next = prev;
        prev = curr;
        curr = fwd;
        return solve(prev,curr,fwd);
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* prev = NULL;       
        ListNode* ans = NULL;       
        ListNode* curr = head;        
        ListNode* fwd =  head;
       ans = solve(prev,curr,fwd);
    return ans;
    }
};