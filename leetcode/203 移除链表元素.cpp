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
    ListNode* removeElements(ListNode* head, int val) {
		while (head != nullptr && head -> val == val){
			ListNode* tmp = head;
			head = head -> next;
			delete tmp;
		}
		for (ListNode* cur = head; cur != nullptr; cur = cur -> next){
			while (cur -> next != nullptr && cur -> next -> val == val){
				ListNode* tmp = cur -> next;
				cur -> next = tmp -> next;
				delete tmp;
			}
		}
		return head;
    }
};
