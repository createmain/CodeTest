#include <iostream>

#include <algorithm>
#include <ctime>

using namespace std;


extern void add(char* key, char* value);
extern void remove(char* key);
extern char* find(char* key);


char* generateRandomString(size_t length)
{
	const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t charmapLength = strlen(charmap);
	auto generator = [&]() { return charmap[rand() % charmapLength]; };
	string result;
	result.reserve(length);
	generate_n(back_inserter(result), length, generator);
	//return &result[0];

	char* ca = new char[result.size() + 1];
	std::copy(result.begin(), result.end(), ca);
	ca[result.size()] = '\0';

	return ca;
}

int main() {
	time_t begin, end;

	time(&begin);
	int i = 0;
	while (i < 10000) {

		char* key = generateRandomString(10);
		char* value = generateRandomString(10);

		//cout << "key:" << key << " value:" << value << endl;

		add(key, value);
		//cout << "stored value: " << find(key) << endl;
		//find(key);
		char* stored = find(key);
		if (stored == NULL) {
			cout << "Error" << endl;
		}
		else if (strcmp(value, stored)) {
			cout << "Error diff" << endl;
		}
		else {
			//cout << value << " " << stored << endl;
			//cout << "Error stored: " << stored << endl;
		}
		/*
		remove(key);
		char* stored = find(key);
		if (stored == NULL) {
			//cout << "removed" << endl;
		}
		else {
			//cout << "stored: " << stored << endl;
		}
		*/

		delete(key);
		delete(value);

		i++;
	}
	time(&end);

	double difference = difftime(end, begin);
	printf("time taken for function() %.2lf seconds.\n", difference);

	return 0;
}