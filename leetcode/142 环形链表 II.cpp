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
        unordered_set<ListNode*> set;
        ListNode* cur = head;
        while (cur != nullptr){
        	if (set.count(cur)) return cur;
        	set.insert(cur);
        	cur = cur->next;
        }
        return nullptr;
    }
};

//¿ìÂýÖ¸Õë 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
		ListNode* slow = head;
		while (1){
			if (fast == nullptr) break;
			if (fast->next == nullptr) break;
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow){
				fast = head;
				while(fast != slow){
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
		}
		return nullptr; 
    }
};
