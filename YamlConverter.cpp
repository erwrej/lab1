#include "YamlConverter.h"

vector<int> arr_build(vector<int> arr) {

	int size;
	cout << "print size" << endl;
	cin >> size;

	int value;

	for (int i = 0; i < size; i++) {
		cin >> value;
		arr.push_back(value);
	}

	return arr;
}

void arr_print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}


//std::string
vector<int> yamltoArr(string str) {
	vector<int> arr;
	string line;
	stringstream ss(str);

	getline(ss, line);

	while (getline(ss, line)) {
		line.erase(0, 6);
		int num;
		num = stoi(line);
		arr.push_back(num);
	}

	return arr;
}

string Arrtoyaml(vector<int> arr, string name) {
	string str;
	str += name;
	str += ": \n";

	for (int i = 0; i < arr.size(); i++) {
		str += "    - ";
		str += to_string(arr[i]);
		str += "\n";
	}

	return str;
}

//char*  + /0

vector<int> yamltoArr(char *str) {
	vector<int> arr;
	string line;
	stringstream ss(str);

	getline(ss, line);

	while (getline(ss, line)) {
		line.erase(0, 6);
		int num;
		num = stoi(line);
		arr.push_back(num);
	}

	delete (str);

	return arr;
}

char *Arrtoyaml(vector<int> arr, const char *name) {
	char *str = (char*) malloc(sizeof(char) * 1000);
	str[0] = '\0';
	strncat(str, name, strlen(name) + 1);
	strncat(str, ":\n", 3);

	for (int i = 0; i < arr.size(); i++) {
		strncat(str, "    - ", 7);
		char number[20];
		sprintf(number, "%d", arr[i]);
		strncat(str, number, 20);
		strncat(str, "\n", 2);
	}

	cout << str;

	return str;
}

//char* + size_t