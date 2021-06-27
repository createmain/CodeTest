#include <iostream>
#include <string>
#include <list>


#include <algorithm>

using namespace std;



class Node {

	private:
	string key;
	string value;

	public:
	Node(string key, string value) {
		this->key = key;
		this->value = value;
	};

	string getKey() {
		return key;
	}

	string getValue() {
		return value;
	}
};

list<Node*>* nodeList;


bool sort(Node* a, Node* b) {
	return a->getKey() < b->getKey();
}

char* generateRandomString(size_t length)
{
	const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t charmapLength = strlen(charmap);
	auto generator = [&]() { return charmap[rand() % charmapLength]; };
	string result;
	result.reserve(length);
	generate_n(back_inserter(result), length, generator);

	char* ca = new char[result.size() + 1];
	copy(result.begin(), result.end(), ca);
	ca[result.size()] = '\0';

	return ca;
}

int main() {

	nodeList = new list<Node*>();

	
	for (int i = 0; i < 10000; i++) {
		
		nodeList->push_front(new Node(generateRandomString(10), generateRandomString(10)));
	}
	list<Node*>::iterator it = nodeList->begin();

	while (it != nodeList->end()) {
		//cout << (*it)->getKey() << endl;
		++it;
	}

	cout << nodeList->size() << endl;
	nodeList->sort(sort);
	it = nodeList->begin();
	cout << nodeList->size() << endl;

	while (it != nodeList->end()) {
		//cout << (*it)->getKey() << endl;
		++it;
	}
	while (nodeList->empty() == false) {
		//delete(nodeList->front());
		Node* node = nodeList->front();
		nodeList->remove(node);
		delete(node);
	}
	

	cout << nodeList->size() << endl;

	nodeList->clear();
	delete(nodeList);
	return 0;
}