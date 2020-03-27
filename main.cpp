#include <iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

#include "create_dic.cpp"

using namespace std;

int main()
{
  unordered_map<string, int> corpus;
  create_dict(corpus);

//   vector<vector<string> > input;
//   read_input(input);
//   print_vec(input);
//   cout << endl; 

//   vector<vector<string> > input_transpose = transpose_matrix(input);
//   vector<vector<string> > result = reorder(corpus,input_transpose);
  
//   display_out(transpose_matrix(result));
//   return 0;
}