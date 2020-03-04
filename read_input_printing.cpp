#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

//Reads the scrambled input data from input.txt file.
void read_input(vector<vector<string> >& input)
{
  ifstream file("soundhound.txt");
  string line;

  while(getline(file, line)){
    vector<string> temp;
    size_t newpos;
    size_t pos=0;
    while(pos < line.size()){
      newpos = line.find_first_of("|", pos);
      if(pos != newpos){
        temp.push_back(line.substr(pos,newpos-pos));
      }
      pos = newpos + 1;
    }
    input.push_back(temp);
  }
  file.close();
  cout << "Reading done!" << endl;
}

void print_vec(const vector<vector<string> >& input)
{
  for( uint i=0; i< input.size(); ++i){
    for( uint j=0; j< input[i].size(); ++j)
      cout << "(" << input[i][j] << ")" ;
    cout << endl;
   }
  cout << "Printing done!" << endl;
}


int main()
{
//   unordered_map<string, int> corpus;
//   create_dict(corpus);

  
  vector<vector<string> > input;
  read_input(input);
  print_vec(input);
  cout << endl; 

//   vector<vector<string> > input_transpose = transpose_matrix(input);
//   vector<vector<string> > result = reorder(corpus,input_transpose);
  
//   display_out(transpose_matrix(result));
//   return 0;
}