#include <fstream>

#include "Shredder.h"

using namespace std;

void Shredder::CreatDict(unordered_map<string, int>& corpus)
{
  cout << "Creating a dictionary" << endl;
  ifstream file("/root/ahmed/Repositories-Mine/text-sharadder/includes/dict.txt");
  string str("");
  char c, prev;
  file.get(prev);
  str += prev;
  for( uint i=1; i< 4; ++i)
  {
    file.get(c);
    if(prev == ' ' && c == ' ')
    {
      while(file.get(c))
      {
        if(c != prev)
        break;
      }
    }
    str += c;
    prev = c;
  }

  corpus[str]++;
  corpus["count"]++;
  while(file.get(c))
  {
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