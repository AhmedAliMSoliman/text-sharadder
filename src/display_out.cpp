#include "include.h"

void display_out(const vector<vector<string> >& input)
{
  cout << "===OUT=== Displaying rsult enter ... " << endl;
  for( uint i=0; i< input.size(); ++i)
  {
    for( uint j=0; j< input[i].size(); ++j)
      cout << input[i][j];
    cout << endl;
   }
  cout << "===OUT=== Displaying rsult excit ... " << endl;
}