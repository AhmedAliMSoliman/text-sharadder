#include <iostream>
#include <vector>
#include <unordered_map>

class Shredder
{
public: 
    //Creating dic of 4-grams with its frequency distrubition 
    void CreatDict(std::unordered_map<std::string, int>& corpus);

    //Returing likelihood of substring str being a valid 4-gram 
    float Probability(std::unordered_map<std::string , int>& corpus , std::string str);

    // Reads the srabled input data from ***.txt file 
    void ReadInput(std::vector<std::vector<std::string>>& input);
};