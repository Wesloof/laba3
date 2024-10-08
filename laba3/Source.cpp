#include <iostream>

using namespace std;


struct PriorityQueue {

	void PriorityQueueElements(string name, int priority) {
		this->name = name;
		this->priority = priority;
	}

	PriorityQueue() {
	}

	PriorityQueue* left = nullptr;
	PriorityQueue* right = nullptr;
	string name;
	int priority;
};



void push(PriorityQueue* queue, PriorityQueue* element) {


	if (queue->right == nullptr) {
		queue->right = element;
		element->left = queue;
		return;
	}

	PriorityQueue* new_element = new PriorityQueue;
	new_element->name = element->name;
	new_element->priority = element->priority;

	PriorityQueue* Ptr = queue->right;
	while (Ptr != nullptr) {

		if (new_element->priority >= Ptr->priority) {
			new_element->right = Ptr;
			new_element->left = Ptr->left;
			Ptr->left->right = new_element;
			Ptr->left = new_element;
			break;
		}

		if (Ptr->right == nullptr) {
			Ptr->right = new_element;
			new_element->left = Ptr;
			break;
		}

		Ptr = Ptr->right;
	}


}


void pop(PriorityQueue* queue) {


	if (queue->right == nullptr) {
		cout << "queue is empty" << endl;
		return;
	}

	PriorityQueue* Ptr = queue->right;

	queue->right = queue->right->right;
	queue->right->right->left = queue;

	delete Ptr;
}


int main() {


	PriorityQueue* PriorityQ = new PriorityQueue;


	PriorityQueue t1;
	t1.PriorityQueueElements("vlad", 5);
	PriorityQueue t2;
	t2.PriorityQueueElements("egor", 20);
	PriorityQueue t3;
	t3.PriorityQueueElements("nikita", 13);
	PriorityQueue t4;
	t4.PriorityQueueElements("anton", 1);
	PriorityQueue t5;
	t5.PriorityQueueElements("gosha", -7);
	PriorityQueue t6;
	t6.PriorityQueueElements("pasha", 5);


	push(PriorityQ, &t1);
	push(PriorityQ, &t2);
	push(PriorityQ, &t3);
	push(PriorityQ, &t4);
	push(PriorityQ, &t5);

	for (PriorityQueue* ptr = PriorityQ->right; ptr != nullptr; ptr = ptr->right) {
		cout << "name " << ptr->name << " priority " << ptr->priority << endl;
	}
	cout << endl << endl;

	pop(PriorityQ);
	pop(PriorityQ);
	push(PriorityQ, &t6);

	for (PriorityQueue* ptr = PriorityQ->right; ptr != nullptr; ptr = ptr->right) {
		cout << "name " << ptr->name << " priority " << ptr->priority << endl;
	}


	return 0;
}

