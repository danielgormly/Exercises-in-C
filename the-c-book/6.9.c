/* Exercise 6.9
 * Find out what a doubly linked list is. Reimplement the linked list example using one.
 * Is it any easier to insert and delete elements in a doubly linked list?
 *
 * Not much of a linked list, we will always provide the root of the list
 * and only provide a method to push towards the end, which will traverse from the root.
 */

#include <stdio.h>
#include <stdlib.h>

// doubly linked list node definition
struct doubly {
	int data;
	struct doubly *prev, *next;
};

void dbly_push(struct doubly *root, int data);
void dblyDump(struct doubly *lastNode);

int main(void) {
	// Build root node
	struct doubly root = { 5, 0, 0 };
	struct doubly *rp = &root;
	//push new nodes to end of doubly list
	dbly_push(rp, 20);
	dbly_push(rp, 22);
	dbly_push(rp, 18);
	dblyDump(rp);
}

// Traverse a doubly linked list node & add a node to the end
void dbly_push(struct doubly *lastNode, int data) {
	
	// Get last member of linked array
	while(lastNode->next != 0) {
		lastNode = lastNode->next;
	}
	
	// Return pointer to malloc'd doubly. Dat dynamic declaration.
	struct doubly *newNode = malloc (sizeof *newNode);
	if (newNode == 0) {
		printf("Warning: malloc failed when attempting to insert %i\n", data);
		return;
	}
	
	// backlink last member to new member
	lastNode->next = newNode;
	
	// populate new member
	newNode->prev = lastNode;
	newNode->data = data;
	newNode->next = 0;
}

void dblyDump(struct doubly *lastNode) {
	int i = 0;
	while(lastNode->next !=0) {
		printf("Node %i: int %i\n", i++, lastNode->data);
		lastNode = lastNode->next;
	}
	// Ok I'm too lazy to refactor this func and avoid this second call. It's really just for debugging.
	printf("Node %i: int %i\n", i++, lastNode->data);
}