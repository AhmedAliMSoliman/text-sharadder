#include <include.h>

vector<vector<string> > transpose_matrix(vector<vector<string> >& input)
{
  cout << "Enter Transpose function" << endl;
  uint height = input.size();
  uint width = input[0].size();
  
  vector<vector<string> > result;

  for( uint i=0; i < width; ++i){
    vector<string> temp;
    for( uint j=0; j< height; ++j){
      temp.push_back(input[j][i]);
    }
    result.push_back(temp);
  }
  return result;
  cout << "Excit Transpose function" << endl;
}