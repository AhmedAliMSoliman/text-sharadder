#include "include.h"

//Reads the scrambled input data from input.txt file.
void read_input(vector<vector<string> >& input)
{
  cout << "===OUT=== Reading started ... " << endl;
  ifstream file("assets/soundhound.txt");
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
  cout << "===OUT=== Reading done!" << endl;
}
