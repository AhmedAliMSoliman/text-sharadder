#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

//Creates a dictionary of 4-grams with its frequency distribution


void create_dict(unordered_map<string, int>& corpus)
{
  cout << "Creating a dictionary ..." << endl;
  ifstream file("dict.txt");
  string str("");
  char c, prev;
  file.get(prev);
  str += prev;
  for( uint i=1; i< 4; ++i)
  {
    file.get(c);
    if(prev == ' ' && c == ' ')
    {
      while(file.get(c)){
        if(c != prev)
	  break;
      }
    }
    str += c;
    prev = c;
  }
  corpus[str]++;
  corpus["count"]++;
  while(file.get(c)){
    if( prev == ' ' && c == ' ')
    {
      while(file.get(c))
      {
        if(c != prev)
        {
	        break;
        }
      }
    }
    prev = c;
    str += c;
    str.erase(str.begin());
    corpus[str]++;
    corpus["count"]++;
  }
  file.close();
  cout << "Done with the dictionary" << endl;
}

/*
  Returns likelihood of substring str being a valid 4-gram.
*/
float probability(unordered_map<string, int>& corpus, string str)
{
  return float((float)(corpus[str]+1)/ (float)(corpus.size()+corpus["count"]));
}


int main()
{
  unordered_map<string, int> corpus;
  create_dict(corpus);

  cout << probability(corpus, "uiuiui") << endl;

  
//   vector<vector<string> > input;
//   read_input(input);
//   print_vec(input);
//   cout << endl; 

//   vector<vector<string> > input_transpose = transpose_matrix(input);
//   vector<vector<string> > result = reorder(corpus,input_transpose);
  
//   display_out(transpose_matrix(result));
  return 0;
}