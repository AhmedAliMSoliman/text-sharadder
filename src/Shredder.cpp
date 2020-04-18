#include <fstream>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h> 

using namespace std;

const std::string kDicttionarySmall{"../includes/dict.txt"};
const std::string kDicttionaryBig{"../includes/big.txt"};
const std::string kInputFile1{"../includes/input.txt"};
const std::string kInputFile2{"../includes/input2.txt"};
const std::string kInputHcl{"../includes/hcl.txt"};

void CreatDict(unordered_map<string, int>& corpus)
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


float Probability(std::unordered_map<std::string , int>& corpus , std::string str)
{
  return float((float)(corpus[str]+1) / (float)(corpus.size() + corpus["count"]));

  cout << "Out of Probbility function!" << std::endl;
}


void ReadInput(std::vector<std::vector<std::string>>& input)
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


float StripCorrction(std::unordered_map<std::string, int>& corpus, std::vector<std::string> left, std::vector<std::string> right)
{
  float prod = 1;
  for( uint i=0; i< left.size(); ++i)
  {
    prod *= Probability(corpus, (left[i]+right[i]) );
  }
  // std::cout << "Out of strip correction function! , with prod = " << prod << std::endl;
  return prod;
}


void PrintVector(const std::vector<std::vector<std::string>>& input)
{
    for(uint i=0; i< input.size(); ++i)
    {
      for( uint j=0; j< input[i].size(); ++j)
        {
          std::cout << "(" << input[i][j] << ")" ;
        }
      std::cout << std::endl;
    }
   std::cout << "Out of print vector func " << std::endl;
}


void DisplayOut(const std::vector<std::vector<std::string> >& input)
{
  for (uint i=0; i< input.size(); ++i)
  {
    for (uint j=0; j< input[i].size(); ++j)
    {
      std::cout << input[i][j];
    }
    std::cout << std::endl;
  }
}

std::vector<std::vector<std::string>> Reorder(std::unordered_map<std::string, int>& corpus, std::vector<std::vector<std::string> >& input)
{
  int ele1, ele2;
  float max_pair_prob = float(-INT_MAX);
  vector<vector<string> > correct_strips;
  for( uint i=0; i < input.size(); ++i)
  {
    for( uint j=0; j< input.size(); ++j)
    {
      if( i != j)
      {
        float pair_prob = StripCorrction(corpus, input[i], input[j]);
	      if(pair_prob > max_pair_prob)
        {
          ele1 = i; ele2 = j;
          max_pair_prob = pair_prob;
        }
      }
    }
  }
  correct_strips.push_back(input[ele1]);
  correct_strips.push_back(input[ele2]);
  
  if(ele1 > ele2)
  {
    input.erase(input.begin() + ele1);
    input.erase(input.begin() + ele2);
  }
  else
  {
    input.erase(input.begin() + ele2);
    input.erase(input.begin() + ele1);
  }
  
  while(input.size())
  {
    float max_left = float(-INT_MAX);
    float max_right = float(-INT_MAX);
    int right_index;
    int left_index;
    int del_index;
 
    for (uint i=0; i< input.size(); ++i)
    {
      float left_prob = StripCorrction(corpus, input[i], correct_strips[0]);
      if(left_prob > max_left)
      {
        left_index = i;
        max_left = left_prob;
      }

      float right_prob = StripCorrction(corpus, correct_strips[correct_strips.size()-1], input[i]);
      if (right_prob > max_right)
      {
        right_index = i;
        max_right = right_prob;
      }
    }
    if (max_right >= max_left)
    {
      correct_strips.push_back(input[right_index]);
      del_index = right_index;
    }  
    else
    {
      correct_strips.insert(correct_strips.begin(), input[left_index]);
      del_index = left_index;
    }
    input.erase(input.begin()+del_index);
  } 
  return correct_strips;
}


std::vector<std::vector<std::string> > TrasnposeMatrix(std::vector<std::vector<std::string> >& input)
{
  uint height = input.size();
  uint width = input[0].size();
  
  std::vector<std::vector<std::string>> result;

  for( uint i=0; i < width; ++i)
  {
    vector<string> temp;
    for( uint j=0; j< height; ++j)
    {
      temp.push_back(input[j][i]);
    }
    result.push_back(temp);
  }
  return result;
}