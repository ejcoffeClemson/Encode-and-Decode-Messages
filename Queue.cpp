/*
 *Queue.cpp, the files goal is to create functions that support a Dynamic Queue (using a Linked List).
 */
#include<iostream>
#include"Queue.h"
#include <cstdlib>
using namespace std;

/*
 *Constructor that establishes the front and rear pointer.
*/
Queue::Queue(){
	front = nullptr;
	rear = nullptr;
	count = 0;
	maxQueue = 100;
}

/*
 * Destructor, Is called after everything is done in Queue.
*/
Queue::~Queue(){
	QueueNode * garbage = front;
	while (garbage != nullptr){
		front = front->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = front;
	}
}
/*
 *This isFull Function checks and sees if the Queue had reached its maximumm size of 100, returns true if it is.
*/
bool Queue::isFull() const{
	//maxQueue = 100
	if (count > maxQueue){
		return true;
	}

	else{
		return false;
	}
}

/*
 *Defines this functions checks if Queue is empty, returns true if its empty.
*/
bool Queue::isEmpty() const{
	if (front == nullptr){
		return true;
	}

	else{
		return false;
	}
}

/*
 *Function enqueue that inserts a value of num
 *to the rear of the queue.
*/
void Queue::enqueue(int num){
	if (isEmpty()){
		front = new QueueNode(num);
		rear = front;
	}
	else{
		//See if queue has reached the limit of 100 
		if(isFull()){
		//cout<<"Queue is Full (temp response)." << endl;
		}
		//If queue didn't reach limit, adds num to the queue. 
		else{ 
		rear->next = new QueueNode(num);
		rear = rear->next;
		++count;
		}
	}
}

/*
 * The dequeue functions removes character from queue (at the front), copies it before its removed.
*/
void Queue::dequeue(int &num){
	QueueNode *temp = nullptr;
	if (isEmpty()){
		cout << "Queue empty, Nothing to remove." << endl;
		//exit(1);Maybe remove, will make you have to make run again. 
	}
	else{
		//removes character from the queue.
		num = front->value;
		saveValue = num;
		temp = front;
		--count;
		front = front->next;
		delete temp;
		
	}
}

void Queue::clear(){
	//cout << "\nIn clear: ";
	while(isEmpty() != true){
	int value;
	dequeue(value);
	cout << value << " ";
	}
}
