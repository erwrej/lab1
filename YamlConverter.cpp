#include "YamlConverter.h"

vector<int> arrbuild(vector<int> arr, string &p_name) {
	cout << "Print yaml name: \n";
	cin >> p_name;
	p_name += ":\n";

	int a, count;
	cout << "Print arr element count: \n";
	cin >> count;

	if (count <= 0) {
		throw invalid_argument("Element count must be greater than 0");
	}
	for (int i = 0; i < count; i++) {
		cout << "Print arr element: " << endl;
		cin >> a;
		while (cin.fail()) {
			cin.clear();
			cout << "Incorrect element format. Try again" << endl;
			cin >> a;
		}
		arr.push_back(a);
	}
	return arr;
}

void arr_print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << i << " - " << arr[i] << endl;
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

	for (int number: arr) {
		str += "    - ";
		str += to_string(number);
		str += '\n';
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

	return arr;
}

char *Arrtoyaml(vector<int> arr, const char *name) {
	char *str;
	char *buff;
	str = (char *) malloc(sizeof(char) * (strlen(name) + 1));
	strncpy(str, name, strlen(name));
	str[strlen(name)] = '\0';

	for (int number: arr) {
		str = (char *) realloc(str, sizeof(char) * (8 + strlen(str)));
		strncat(str, "    - ", 8);
		str = (char *) realloc(str, sizeof(char) * ((to_string(number)).length() + strlen(str) + 1));
		strncat(str, (to_string(number)).c_str(), (to_string(number)).length());
		str = (char *) realloc(str, sizeof(char) * (2 + strlen(str)));
		strncat(str, "\n", 2);
	}


	cout << str;
	return str;
}

//char* + size_t

void print_strarr(char *str, int count) {
	for (int i = 0; i < count; i++) {
		cout << str[i];
	}
}

vector<int> yamltoArr(const char *str, int &count) {
	vector<int> arr;
	string num;
	int name_len = 1;
	for (int i = 0; i < count; i++) {
		if (str[i] != '\n') {
			name_len++;
		} else {
			break;
		}
	}
	for (int i = name_len - 1; i < count; i++) {

		if (str[i] == '\n') {

			if (i == (count - 1)) {

				if (!num.empty()) {
					arr.push_back(stoi(num));
					num.clear();
				}
				break;
			}

			i += 7;

			if (!num.empty()) {
				arr.push_back(stoi(num));
				num.clear();
			}

		}
		num += (str[i]);
	}

	return arr;
}

char *Arrtoyaml(vector<int> arr, const char *name, int &count) {
	char *str;
	str = (char *) malloc(sizeof(char) * strlen(name));
	count = strlen(name);

	for (int i = 0; i < strlen(name); i++) {
		str[i] = name[i];
	}

	for (int i = 0; i < arr.size(); i++) {

		str = (char *) realloc(str, sizeof(char) * (6 + count));
		const char *tmp = "    - ";
		for (int j = count; j < (count + 6); j++) {
			str[j] = tmp[j - count];
		}
		count += 6;

		str = (char *) realloc(str, sizeof(char) * ((to_string(arr[i])).length() + count));
		for (int j = 0; j < (to_string(arr[i])).length(); j++) {
			str[count + j] = (to_string(arr[i])).c_str()[j];
		}
		count += (to_string(arr[i])).length();

		str = (char *) realloc(str, sizeof(char) * (1 + count));
		str[count] = '\n';
		count++;
	}

	return str;
}