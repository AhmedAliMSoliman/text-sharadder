#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;


void print_vec(const vector<vector<string> >& input);
void read_input(vector<vector<string> >& input);
void create_dict(unordered_map<string, int>& corpus);