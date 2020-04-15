#include <fstream>

#include "Shredder.h"


using namespace std;

void Shredder::CreatDict(unordered_map<string, int>& corpus)
{
  cout << "Creating a dictionary" << endl;
  ifstream dict_file(kDicttionarySmall);
  string str("");
  char c, prev;
  dict_file.get(prev);
  str += prev;
  for( uint i=1; i< 4; ++i)
  {
    dict_file.get(c);
    if(prev == ' ' && c == ' ')
    {
      while(dict_file.get(c))
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
  while(dict_file.get(c))
  {
    if( prev == ' ' && c == ' ')
    {
      while(dict_file.get(c))
      {
        if(c != prev) { break; }
      }
    }
    
    prev = c;
    str += c;
    str.erase(str.begin());
    corpus[str]++;
    corpus["count"]++;
  }

  dict_file.close();
  cout << "Done with the dictionary" << endl;
}


float Shredder::Probability(std::unordered_map<std::string , int>& corpus , std::string str)
{
  return float((float)(corpus[str]+1) / (float)(corpus.size() + corpus["count"]));

  cout << "Out of Probbility function!" << std::endl;
}


void Shredder::ReadInput(std::vector<std::vector<std::string>>& input)
{
  ifstream file(kInputHcl);
  string line;

  while(getline(file, line))
  {
    vector<string> temp;
    size_t new_pos, pos = 0;

    while(pos < line.size())
    {
      new_pos = line.find_first_of("|", pos);
      if (pos != new_pos)
      {
        temp.push_back(line.substr(pos, new_pos - pos));
      }
      pos = new_pos + 1;
    }
    input.push_back(temp);

    for (int i = 0 ; i < temp.size() ; i++)
    {
      cout << temp[i] << endl;
    }
  }
  file.close();

  cout << "Out of Read Input function!" << std::endl;
}