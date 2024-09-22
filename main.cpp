#include "YamlConverter.h"

int main(){
	vector<int> arr;

	//string
	// string name;
	// cin>>name;
	// arr = arr_build(arr);
	// name += '\0';
	// string str;
	// str = Arrtoyaml(arr, name);
	// cout<<str;

	// arr = yamltoArr(str);
	// arr_print(arr);

	//char
	cout<<"name: \n";
	string name_str;
	getline(cin, name_str, '\n');
	arr = arr_build(arr);
	const char *name = name_str.c_str();
	char* str;
	str = Arrtoyaml(arr, name);
}