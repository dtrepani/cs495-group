#ifndef _NODE_
#define _NODE_

#include "Entity.h"

class Node {
private:
	Entity* entity;
	Node* next;

public:
	Node(Entity* anEntity, Node* aNext);
	~Node(void);
	Node* getNext();
	Entity* getEntity();
};

#endif