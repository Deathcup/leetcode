class MyLinkedList {
public:
	int size;
	struct ListNode{
		int val;
		ListNode *next;
		ListNode(int val): val(val),next(nullptr){}
		ListNode(): val(0),next(nullptr){}
		ListNode(int val, ListNode *next): val(val),next(next){}
	};
	ListNode* dummyHead;
    /** Initialize your data structure here. */
    MyLinkedList() {
		dummyHead = new ListNode();
		size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
		if (index > size - 1 || index < 0){
			return -1;
		}
		ListNode* cur = dummyHead->next;
		while (index--){
			cur = cur->next;
		}
		return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
		ListNode* newNode = new ListNode(val, dummyHead->next);
		dummyHead->next = newNode;
		size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
    	ListNode* newNode = new ListNode(val);
		ListNode* cur = dummyHead;
		while (cur->next != nullptr){
			cur = cur->next;
		}
		cur->next = newNode;
		size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
    	if(index > size) return;
		ListNode* newNode = new ListNode(val);
		ListNode* cur = dummyHead;
		while (index--){
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
		if(index > size - 1 || index < 0) return;
		ListNode* cur = dummyHead;
		while(index--){
			cur = cur->next;
		}
		ListNode* tmp = cur->next;
		cur->next = tmp->next;
		delete tmp;
		size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
