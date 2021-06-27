#include <iostream>
#include <string>

using namespace std;


//This is memory copy
//Impossible without memory copy for char* return
char* convertToChar(string source)
{
	char* result = new char[source.size() + 1];

	copy(source.begin(), source.end(), result);
	result[source.size()] = '\0';
	return result;
}

string replaceAll(string source, string target, string value) {
	if (target.compare(value) == 0) {
		return source;
	}
	
	unsigned int index = source.find(target);
	while (index != string::npos) {
		source.replace(index, target.size(), value);
		index += value.size();
		index = source.find(target, index);
	}
	return source;
}

int main() 
{
	string test = "test";



	char* result = convertToChar(test);
	cout << result << endl;

	delete (result); //if not, it's leak


	test.append("asdf");
	test.append("1234");
	cout << test << endl;

	
	string asdf = "asdf";


	cout << test.replace(test.find(asdf), asdf.size(), "asdfhjkasdhfjkasdhjkfhjkasdf") << endl;
	
	cout << test.compare(test.substr(0, test.size())) << endl;
	cout << test.substr(0, test.size()) << endl;

	test = replaceAll(test, "t", "test");
	cout << test << endl;
	test = replaceAll(test, "tes", "a");
	cout << test << endl;
	return 0;
}