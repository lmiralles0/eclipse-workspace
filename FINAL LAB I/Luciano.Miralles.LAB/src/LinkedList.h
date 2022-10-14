/*
 * LinkedList.h
 *
 *  Created on: 14 oct. 2022
 *      Author: MCvitani
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct Node
{
	void* pElement;
	struct Node* pNextNode;
}typedef Node;

typedef struct
{
	Node* pFirstNode;
	int size;
}LinkedList;


LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index, void* pElement);
int ll_remove(LinkedList* this, int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this, int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this, LinkedList* this2);
LinkedList* ll_subList(LinkedList* this, int from, int to);
LinkedList* ll_clone(LinkedList* this);





#endif /* LINKEDLIST_H_ */
