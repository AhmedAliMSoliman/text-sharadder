#include <include.h>

float strip_correction(unordered_map<string, int>& corpus, vector<string> left, vector<string> right)
{
  float prod = 1;
  for( uint i=0; i< left.size(); ++i){
    prod *= probability(corpus, (left[i]+right[i]) );
  }
  return prod;
}

float probability(unordered_map<string, int>& corpus, string str)
{
  return float((float)(corpus[str]+1)/ (float)(corpus.size()+corpus["count"]));
}