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


int main() 
{
	string test = "test";
	char* result = convertToChar(test);
	cout << result << endl;

	delete (result); //if not, it's leak


	return 0;
}