/*
 *Queue.h, Functions and variables created for Queue.cpp.
 *Information used to bulid Class Queue can be found on pg.1204.
*/
#ifndef QUEUE_H
#define QUEUE_H

class Queue{
	struct QueueNode{
		int value;
		QueueNode *next;
		QueueNode(char value1, QueueNode *next1 = nullptr){
			value = value1;
			next = next1;
		}
	};
	//Nodes that Keep track of positions for the front and back node.
	QueueNode *front;
	QueueNode *rear;

	public:
	//These are the Constructor and Deconstructor of the Class.
	Queue();
	~Queue();
	int count;
	int maxQueue;
	int saveValue;//Saves value before its dequeued.

	//Memeber Functions
	void enqueue(int); //Used to add an eleement to the rear of the Queue.
	void dequeue(int &); // Used to remove an element from the front of the Queue.
	bool isEmpty() const; // Used to check if the Queue is empty.
	bool isFull() const; // Used to check if Queue is fill.
	void clear();

};
#endif
