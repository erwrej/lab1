#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

vector<int> arr_build(vector<int> arr);

string Arrtoyaml(vector<int> arr, string name);
char* Arrtoyaml(vector<int> arr, const char* name);

vector<int> yamltoArr(string str);
vector<int> yamltoArr(char* str);

void arr_print(vector<int> arr);