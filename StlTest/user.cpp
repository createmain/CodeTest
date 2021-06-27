#include <iostream>
#include <string>
#include <list>

#include <algorithm>
#include <ctime>

#define NULL nullptr
#define MAX_HASH_TABLE 10 //Size of hash Table, You can evaluate performance by hash table size.
/*
 stl's hash value has unsigned int type. This is limited hash size by modulo operation.
 for duplicated hash key, it has list for avoid duplicated item management with linear search.
*/

using namespace std;


struct Node {
	string key;
	string value;
};

list<Node*>* hashTable[MAX_HASH_TABLE] = { NULL, };


Node* findNode(list<Node*>* source, char* key) {
	string objKey = string(key);
	list<Node*>::iterator it = source->begin();

	while (it != source->end()) {
		Node* node = *it;
		if (objKey.compare(node->key) == 0) {
			return node;
		}
		++it;
	}

	return NULL;
}

void add(char* key, char* value) {

	string objKey = string(key);
	unsigned int hashed = hash<string>{}(objKey) % MAX_HASH_TABLE;

	//cout << "hashed: " << hashed << endl;
	if (hashTable[hashed] == NULL) {
		list<Node*>* nodeList = new list<Node*>();
		Node* node = new Node();
		node->key = string(key);
		node->value = string(value);

		nodeList->push_back(node); // push_front(node);
		hashTable[hashed] = nodeList;
	}
	else
	{
		list<Node*>* nodeList = hashTable[hashed];
		Node* node = findNode(nodeList, key);
		if (node == NULL) {
			//Not exist
			Node* newNode = new Node();
			newNode->key = string(key);
			newNode->value = string(value);

			nodeList->push_back(newNode);
		}
		else {
			//Exist
			node->value = string(value); //Update
		}
	}
}

char* find(char* key) {

	string objKey = string(key);
	unsigned int hashed = hash<string>{}(objKey) % MAX_HASH_TABLE;

	if (hashTable[hashed] != NULL) {
		Node* node = findNode(hashTable[hashed], key);

		if (node != NULL) {
			//Node is not deleted. So it's working.
			return const_cast<char*>(node->value.c_str());
		}
	}

	return NULL;
}

void remove(char* key) {
	string objKey = string(key);
	unsigned int hashed = hash<string>{}(objKey) % MAX_HASH_TABLE;
	if (hashTable[hashed] != NULL) {

		Node* node = findNode(hashTable[hashed], key);
		if (node != NULL) {
			hashTable[hashed]->remove(node);
			delete(node);
		}
	}
}

