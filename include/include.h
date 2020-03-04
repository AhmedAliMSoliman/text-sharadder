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
void display_out(const vector<vector<string> >& input);
vector<vector<string> > transpose_matrix(vector<vector<string> >& input);
vector<vector<string> > reorder(unordered_map<string, int>& corpus, vector<vector<string> >& input);
float strip_correction(unordered_map<string, int>& corpus, vector<string> left, vector<string> right);
float probability(unordered_map<string, int>& corpus, string str);

