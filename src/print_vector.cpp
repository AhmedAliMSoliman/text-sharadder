#include "include.h"

void print_vec(const vector<vector<string> >& input)
{
  cout << "===OUT=== Entering the print vector function" << endl;
  for( uint i=0; i< input.size(); ++i){
    for( uint j=0; j< input[i].size(); ++j)
      cout << "(" << input[i][j] << ")" ;
    cout << endl;
   }
  cout << "===OUT=== Exiting the print vector function" << endl;
}

