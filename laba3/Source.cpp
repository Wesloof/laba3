#include <iostream>

using namespace std;


struct PriorityQueue {

	PriorityQueue(std::string name, int priority) {
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


	PriorityQueue* Head = new PriorityQueue;


	PriorityQueue t1("vlad", 5);
	PriorityQueue t2("egor", 20);
	PriorityQueue t3("nikita", 13);
	PriorityQueue t4("anton", 1);
	PriorityQueue t5("gosha", -7);
	PriorityQueue t6("pasha", 5);


	push(Head, &t1);
	push(Head, &t2);
	push(Head, &t3);
	push(Head, &t4);
	push(Head, &t5);

	for (PriorityQueue* ptr = Head->right; ptr != nullptr; ptr = ptr->right) {
		cout << "name " << ptr->name << " priority " << ptr->priority << endl;
	}
	cout << endl << endl;

	pop(Head);
	pop(Head);
	push(Head, &t6);

	for (PriorityQueue* ptr = Head->right; ptr != nullptr; ptr = ptr->right) {
		cout << "name " << ptr->name << " priority " << ptr->priority << endl;
	}


	return 0;
}

