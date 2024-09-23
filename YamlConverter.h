#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

vector<int> arrbuild(vector<int> arr, string &p_name);

string Arrtoyaml(vector<int> arr, string name);

char *Arrtoyaml(vector<int> arr, const char *name);

vector<int> yamltoArr(string str);

vector<int> yamltoArr(char *str);

void print_strarr(char *str, int count);

vector<int> yamltoArr(const char *str, int &count);

char *Arrtoyaml(vector<int> arr, const char *name, int &count);

void arr_print(vector<int> arr);