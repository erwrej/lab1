#include "YamlConverter.h"

int main() {
	vector<int> arr;
	string name;
	string &p_name = name;
	try {
		arr = arrbuild(arr, p_name);
	} catch (invalid_argument &invalid_argument) {
		cout.clear();
		cout << invalid_argument.what() << endl;
		return 1;
	}
	string str;
	char *str_c;

	while (true) {
		cout << "1 - make yaml string with sdd::string" << endl <<
			 "2 - make yaml string with char* string" << endl <<
			 "3 - make yaml string with char* array" << endl <<
			 "4 - exit" << endl;
		cout << "Chose option: \n";
		int command;
		cin >> command;
		if (command == 1) {
			str = Arrtoyaml(arr, name);
			while (true) {
				cout << "1 - show string" << endl << "2 - string to array\n";
				cin >> command;
				if (command == 1) {
					cout << str;
					command = 0;
				}
				if (command == 2) {
					arr = yamltoArr(str);
					arr_print(arr);
					command = 0;
					break;
				}
			}
		}
		if (command == 2) {

			str_c = Arrtoyaml(arr, name.c_str());
			while (true) {
				cout << "1 - show string\n2 - string to array\n";
				cin >> command;
				if (command == 1) {
					cout << str_c;
					command = 0;
				}
				if (command == 2) {
					arr = yamltoArr(str_c);
					arr_print(arr);
					command = 0;
					free(str_c);
					break;
				}
			}
		}
		if (command == 3) {
			int count;
			int &p_count = count;

			str_c = Arrtoyaml(arr, name.c_str(), p_count);
			while (true) {
				cout << "1 - show string\n2 - string to array\n";
				cin >> command;
				if (command == 1) {
					print_strarr(str_c, count);
					command = 0;
				}
				if (command == 2) {
					arr = yamltoArr(str_c, p_count);
					arr_print(arr);
					command = 0;
					free(str_c);
					break;
				}
			}
		}
		if (command == 4) {
			break;
		}
	}


}

