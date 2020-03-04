#include <include.h>
#include<bits/stdc++.h> 
/*
  Takes in the transposed form of the original input data.
  Reorders the strips into corrected data.
*/

vector<vector<string> > reorder(unordered_map<string, int>& corpus, vector<vector<string> >& input)
{
  cout << "Enter reorder function" << endl;

  int ele1, ele2;
  float max_pair_prob = float(-INT_MAX);
  vector<vector<string> > correct_strips;
  for( uint i=0; i < input.size(); ++i){
    for( uint j=0; j< input.size(); ++j){
      if( i != j){
        float pair_prob = strip_correction(corpus, input[i], input[j]);
	if(pair_prob > max_pair_prob){
          ele1 = i; ele2 = j;
          max_pair_prob = pair_prob;
        }
      }
    }
  }
  correct_strips.push_back(input[ele1]);
  correct_strips.push_back(input[ele2]);
  
  if(ele1 > ele2){
    input.erase(input.begin() + ele1);
    input.erase(input.begin() + ele2);
  }
  else{
    input.erase(input.begin() + ele2);
    input.erase(input.begin() + ele1);
  }
  
  while(input.size()){
    float max_left = float(-INT_MAX);
    float max_right = float(-INT_MAX);
    int right_index;
    int left_index;
    int del_index;
 
    for( uint i=0; i< input.size(); ++i){
      float left_prob = strip_correction(corpus, input[i], correct_strips[0]);
      if(left_prob > max_left){
        left_index = i;
        max_left = left_prob;
      }

      float right_prob = strip_correction(corpus, correct_strips[correct_strips.size()-1], input[i]);
      if(right_prob > max_right){
        right_index = i;
        max_right = right_prob;
      }
    }
    if(max_right >= max_left){
      correct_strips.push_back(input[right_index]);
      del_index = right_index;
    }  
    else{
      correct_strips.insert(correct_strips.begin(), input[left_index]);
      del_index = left_index;
    }
    input.erase(input.begin()+del_index);
  } 
  return correct_strips;
  cout << "Exit Transpose function" << endl;

}
