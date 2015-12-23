/** Simple program that tests reversing a doubly linked list */
#include <iostream>

struct Node {
	int data;
	Node *next;
	Node *prev;
};

/* code to reverse doubly linked list */
static Node *Reverse(Node *head) {
	if(head == NULL) return head;
	if(head->next == NULL) return head;

	Node *cur = head;
	while(cur != NULL) {
		Node *next = cur->next;
		if(next == NULL)
		{
			head = cur;
			std::cout << head->data << std::endl;
		}
		Node *temp = cur->next;
		cur->next = cur->prev;
		cur->prev = temp;
		cur = next;
	}
	return head;
}
/* Print linked list's values */
static void printLL(Node *head) {
	Node *cur = head;
	if(cur == NULL) std::cout << "NULL" << std::endl;
	else std::cout << "[";
	while(cur != NULL) {
		if (cur->next != NULL) 
			std::cout << cur->data << ",";
		else 
			std::cout << cur->data;
		cur = cur->next;
	}
	std::cout << "]" << std::endl;
}

int main(int argc, char *argv[]) {
	Node *node1;
	Node *node2;
	Node *node3;
	/* Node1 */
	node1 = new Node;
	node1->data = 3;
	node1->prev = NULL;
	/* Node2 */
	node2 = new Node;
	node1->next = node2;
	node2->data = 6;
	node2->prev = node1;
	/* Node 3 */
	node3 = new Node;
	node2->next = node3;
	node3->data = 9;
	node3->prev = node2;
	node3->next = NULL;

	/* Set Head */
	Node *head = node1;
	printLL(head);
	Node *new_head = Reverse(head);
	printLL(new_head);
	return 0;
}
