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
    ListNode* reverseList(ListNode* head) {
    	if (head == nullptr) return head;
		ListNode* resDummyHead = new ListNode();
		ListNode* cur = head;
		while (cur != nullptr){
			ListNode* tmp = cur->next;
			cur->next = resDummyHead->next;
			resDummyHead->next = cur;
			cur = tmp;
		}
		return resDummyHead->next;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	ListNode* tmp;
    	ListNode* cur = head;
    	ListNode* pre = nullptr;
		while (cur != nullptr){
			tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
    }
};

class Solution {
public:
	ListNode* reverse(ListNode* pre, ListNode* cur){
		if (cur == nullptr) return pre;
		ListNode* tmp = cur->next;
		cur->next = pre;
		return reverse(cur,tmp);
	}
    ListNode* reverseList(ListNode* head) {
    	return reverse(NULL,head);
    }
};
